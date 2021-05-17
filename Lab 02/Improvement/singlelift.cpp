/**
 * Author: Devansh Jain (190100044)
 * Lab 2 - Single Lift
 */

#include <iostream>
#include <list> // For using list data structure

using namespace std;

// Forward Declaration
class Lift;
class Floor;

/**
 * @class Lift
 * @brief represents the lift
 */
class Lift {
private:
  uint current_loc;          // Stores current location of lift
  uint max_floor;            // Stores max number of floors
  bool *up_wait, *down_wait; // Boolean array to store waiting floors
  bool *dest_list; // Boolean array to store destinations of passengers
  int dir;         // Stores the direction. {-1: DOWN, 0: IDLE, 1: UP}
  Floor **f;       // Pointer to the floors objects

public:
  /**
   * @ctor Lift
   * @param[in] n max_floor
   * @param[in] start initial location
   * @brief allocates space to the boolean arrays
   */
  Lift(uint n, uint start);

  /**
   * @fn assign_floors
   * @param[in] floors pointers to the floors
   * @brief saves the pointers in f
   */
  void assign_floors(Floor *floors[]);

  /**
   * @fn up
   * @param[in] floor_no floor number which presses up button
   * @brief marks the floor on up waiting list
   */
  void up(uint floor_no);

  /**
   * @fn down
   * @param[in] floor_no floor number which presses down button
   * @brief marks the floor on down waiting list
   */
  void down(uint floor_no);

  /**
   * @fn move
   * @brief moves the lift by one in direction dir (doesn't move if dir==0)
   *         opens on the floor if need be
   *         sets the dir if need be
   */
  void move();

  /**
   * @fn incoming
   * @return whether the current floor has waiting list or not.
   */
  bool incoming();
};

/**
 * @class Floor
 * @brief represents the floor
 */
class Floor {
private:
  uint floor_no;  // Stores floor number
  uint max_floor; // Stores max number of floors
  list<uint> waiting_up,
      waiting_down; // To keep tab of the passengers waiting for lifts
  Lift *l;          // Pointer to the lift object

public:
  /**
   * @ctor Lift
   * @param[in] n max_floor
   * @param[in] i floor number
   * @param[in] lift pointer to the lift
   * @brief saves the pointers to l
   */
  Floor(uint n, uint i, Lift *lift);

  /**
   * @fn up
   * @param[in] dest array of destinations of passangers
   * @param[in] k number of passangers waiting for down
   * @brief stores the list of passangers and calls the lift
   */
  void up(uint dest[], uint k);

  /**
   * @fn down
   * @param[in] dest array of destinations of passangers
   * @param[in] k number of passangers waiting for down
   * @brief stores the list of passangers and calls the lift
   */
  void down(uint dest[], uint k);

  /**
   * @fn lift_opens
   * @param[in] dir direction of lift before it opened
   * @return list of passangers getting on the lift.
   * @brief returns and clears the waiting list in the direction dir
   */
  list<uint> lift_opens(int dir);
};

Lift::Lift(uint n, uint start) {
  max_floor = n;
  current_loc = start;
  up_wait = new bool[max_floor];
  down_wait = new bool[max_floor];
  dest_list = new bool[max_floor];
  for (uint i = 0; i <= max_floor; i++) {
    up_wait[i] = false;
    down_wait[i] = false;
    dest_list[i] = false;
  }
  dir = 0;
}

void Lift::assign_floors(Floor *floors[]) { f = floors; }

void Lift::up(uint floor_no) {
  if (floor_no <= max_floor)
    up_wait[floor_no] = true;
}

void Lift::down(uint floor_no) {
  if (floor_no <= max_floor)
    down_wait[floor_no] = true;
}

void Lift::move() {
  if (current_loc == max_floor && dir == 1) {
    dir = 0;
  }
  if (current_loc == 0 && dir == -1) {
    dir = 0;
  }

  current_loc += dir;
  cout << "Lift is at Floor " << current_loc << ". ";

  if (incoming()) {
    list<uint> pass = f[current_loc]->lift_opens(dir);
    for (auto it : pass) {
      dest_list[it] = true;
    }
    if (dest_list[current_loc]) {
      cout << " Passengers get out as well.";
    }
  } else {
    if (dest_list[current_loc]) {
      cout << "Lift opens at Floor " << current_loc << ". Passengers get out.";
    }
  }
  dest_list[current_loc] = false;
  cout << endl;

  if (dir == 1) {
    dir = 0;
    for (uint i = current_loc + 1; i <= max_floor; i++) {
      if (up_wait[i] || down_wait[i] || dest_list[i]) {
        dir = 1;
      }
    }
  }
  if (dir == -1) {
    dir = 0;
    for (uint i = 0; i < current_loc; i++) {
      if (up_wait[i] || down_wait[i] || dest_list[i]) {
        dir = -1;
      }
    }
  }
  if (dir == 0) {
    for (uint i = 0; i <= max_floor; i++) {
      if (up_wait[i] || down_wait[i]) {
        if (i > current_loc) {
          dir = 1;
          break;
        }
        if (i < current_loc) {
          dir = -1;
          break;
        }
      }
    }
  }
  if (dir == 1) {
    up_wait[current_loc] = false;
  }
  if (dir == -1) {
    down_wait[current_loc] = false;
  }
}

bool Lift::incoming() {
  if (dir != -1 && up_wait[current_loc]) {
    dir = 1;
    return true;
  }
  if (dir != 1 && down_wait[current_loc]) {
    dir = -1;
    return true;
  }
  return false;
}

Floor::Floor(uint n, uint i, Lift *lift) {
  max_floor = n;
  floor_no = i;
  l = lift;
}

void Floor::up(uint dest[], uint k) {
  if (floor_no == max_floor) {
    cout << "Floor " << floor_no << " has up button disabled." << endl;
    return;
  }
  cout << "Floor " << floor_no << " pressed up button." << endl;
  for (int i = 0; i < k; i++) {
    if (dest[i] <= max_floor && dest[i] != floor_no) {
      waiting_up.push_back(dest[i]);
    }
  }
  l->up(floor_no);
}

void Floor::down(uint dest[], uint k) {
  if (floor_no == 0) {
    cout << "Floor " << floor_no << " has down button disabled." << endl;
    return;
  }
  cout << "Floor " << floor_no << " pressed down button." << endl;
  for (int i = 0; i < k; i++) {
    if (dest[i] <= max_floor && dest[i] != floor_no) {
      waiting_down.push_back(dest[i]);
    }
  }
  l->down(floor_no);
}

list<uint> Floor::lift_opens(int dir) {
  cout << "Lift opens at Floor " << floor_no
       << ". Passengers get in with destinations: ";
  list<uint> pass;
  if (dir == 1) {
    pass = waiting_up;
    waiting_up.clear();
  }
  if (dir == -1) {
    pass = waiting_down;
    waiting_down.clear();
  }
  for (auto it : pass) {
    cout << it << ", ";
  }
  cout << "\b\b. ";
  return pass;
}

int main(int argc, char *argv[]) {
  uint max_floors = 6;
  Lift *lift = nullptr;
  Floor *floors[max_floors + 1];

  lift = new Lift(max_floors, 0);
  for (uint i = 0; i <= max_floors; i++) {
    floors[i] = new Floor(max_floors, i, lift);
  }
  lift->assign_floors(floors);

  uint pass1[2] = {2, 3}, pass2[2] = {0, 1}, pass3[2] = {5, 6};
  cout << "Start" << endl;

  lift->move();
  // Expected Output: "Lift is at Floor 0. "

  lift->move();
  // Expected Output: "Lift is at Floor 0. "

  floors[0]->up(pass1, 2);
  // Expected Output: "Floor 0 pressed up button."

  floors[1]->up(pass1, 2);
  // Expected Output: "Floor 1 pressed up button."

  lift->move();
  // Expected Output: "Lift is at Floor 0. Lift opens at Floor 0. Passengers get
  // in with destinations: 2, 3. "

  lift->move();
  // Expected Output: "Lift is at Floor 1. Lift opens at Floor 1. Passengers get
  // in with destinations: 2, 3. "

  lift->move();
  // Expected Output: "Lift is at Floor 2. Lift opens at Floor 2. Passengers get
  // out."

  lift->move();
  // Expected Output: "Lift is at Floor 3. Lift opens at Floor 3. Passengers get
  // out."

  lift->move();
  // Expected Output: "Lift is at Floor 3. "

  lift->move();
  // Expected Output: "Lift is at Floor 3. "

  floors[0]->down(pass2, 2);
  // Expected Output: "Floor 0 has down button disabled."

  floors[6]->down(pass2, 2);
  // Expected Output: "Floor 6 pressed down button."

  floors[2]->up(pass3, 2);
  // Expected Output: "Floor 2 pressed up button."

  lift->move();
  // Expected Output: "Lift is at Floor 3. "

  lift->move();
  // Expected Output: "Lift is at Floor 2. "

  lift->move();
  // Expected Output: "Lift is at Floor 3. "

  lift->move();
  // Expected Output: "Lift is at Floor 4. "

  lift->move();
  // Expected Output: "Lift is at Floor 5. "

  lift->move();
  // Expected Output: "Lift is at Floor 6. "

  lift->move();
  // Expected Output: "Lift is at Floor 6. Lift opens at Floor 6. Passengers get
  // in with destinations: 0, 1. "

  lift->move();
  // Expected Output: "Lift is at Floor 5. "

  lift->move();
  // Expected Output: "Lift is at Floor 4. "

  lift->move();
  // Expected Output: "Lift is at Floor 3. "

  lift->move();
  // Expected Output: "Lift is at Floor 2. "

  lift->move();
  // Expected Output: "Lift is at Floor 1. Lift opens at Floor 1. Passengers get
  // out."

  lift->move();
  // Expected Output: "Lift is at Floor 0. Lift opens at Floor 0. Passengers get
  // out."

  lift->move();
  // Expected Output: "Lift is at Floor 0. "

  cout << "End" << endl;

  return 0;
}
