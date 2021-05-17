/**
 * Author: Devansh Jain (190100044)
 * Lab 2 - Two Lifts
 */

#include <iostream>
#include <list> // For using list data structure

using namespace std;

/**
 * @fn abs
 * @param[in] a unsigned integer
 * @param[in] b unsigned integer
 * @return unsigned integer - absolute difference
 * @brief global helper function to compute absolute difference of uints
 */
uint abs(uint a, uint b) {
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}

// Forward Declaration
class Lift;
class Floor;

/**
 * @class Lift
 * @brief represents the lift
 */
class Lift {
private:
  uint id;                   // ID of the lift
  uint current_loc;          // Stores current location of lift
  uint max_floor;            // Stores max number of floors
  bool *up_wait, *down_wait; // Boolean array to store waiting floors
  bool *dest_list; // Boolean array to store destinations of passengers
  int dir;         // Stores the direction. {-1: DOWN, 0: IDLE, 1: UP}
  Floor **f;       // Pointer to the floors objects

public:
  /**
   * @ctor Lift
   * @param[in] lift_no id
   * @param[in] n max_floor
   * @param[in] start initial location
   * @brief allocates space to the boolean arrays
   */
  Lift(uint lift_no, uint n, uint start);

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

  /**
   * @fn get_status
   * @param[out] dir dir
   * @param[out] current_loc current_loc
   * @brief returns dir and current_loc thru call-by-reference
   */
  void get_status(int &dir, uint &current_loc);
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
  Lift *l[2];       // Pointer to the lift objects

public:
  /**
   * @ctor Lift
   * @param[in] n max_floor
   * @param[in] i floor number
   * @param[in] lift0 pointer to the lift 0
   * @param[in] lift1 pointer to the lift 1
   * @brief saves the pointers to l
   */
  Floor(uint n, uint i, Lift *lift0, Lift *lift1);

  /**
   * @fn up
   * @param[in] dest array of destinations of passangers
   * @param[in] k number of passangers waiting for down
   * @brief stores the list of passangers and calls the nearest lift
   */
  void up(uint dest[], uint k);

  /**
   * @fn down
   * @param[in] dest array of destinations of passangers
   * @param[in] k number of passangers waiting for down
   * @brief stores the list of passangers and calls the nearest lift
   */
  void down(uint dest[], uint k);

  /**
   * @fn lift_opens
   * @param[in] dir direction of lift before it opened
   * @return list of passangers getting on the lift.
   * @brief returns and clears the waiting list in the direction dir
   */
  list<uint> lift_opens(int dir);

  /**
   * @fn nearest_lift
   * @param[in] dir direction of the button press
   * @return id of the nearest lift
   * @brief calculates the distance of both lifts
   *         and accordingly calculates nearest lift
   */
  uint nearest_lift(int dir);
};

Lift::Lift(uint lift_no, uint n, uint start) {
  id = lift_no;
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
  cout << "Lift " << id << " is at Floor " << current_loc << ". ";

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

void Lift::get_status(int &dir, uint &current_loc) {
  dir = this->dir;
  current_loc = this->current_loc;
}

Floor::Floor(uint n, uint i, Lift *lift0, Lift *lift1) {
  max_floor = n;
  floor_no = i;
  l[0] = lift0;
  l[1] = lift1;
}

void Floor::up(uint dest[], uint k) {
  if (floor_no == max_floor) {
    cout << "Floor " << floor_no << " has up button disabled." << endl;
    return;
  }
  cout << "Floor " << floor_no << " pressed up button. ";
  for (int i = 0; i < k; i++) {
    if (dest[i] <= max_floor && dest[i] != floor_no) {
      waiting_up.push_back(dest[i]);
    }
  }
  uint near = nearest_lift(1);
  l[near]->up(floor_no);
  cout << "Lift " << near << " is assigned." << endl;
}

void Floor::down(uint dest[], uint k) {
  if (floor_no == 0) {
    cout << "Floor " << floor_no << " has down button disabled." << endl;
    return;
  }
  cout << "Floor " << floor_no << " pressed down button. ";
  for (int i = 0; i < k; i++) {
    if (dest[i] <= max_floor && dest[i] != floor_no) {
      waiting_down.push_back(dest[i]);
    }
  }
  uint near = nearest_lift(-1);
  l[near]->down(floor_no);
  cout << "Lift " << near << " is assigned." << endl;
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

uint Floor::nearest_lift(int dir) {
  int lift_dir[2];
  uint lift_locs[2];
  uint lift_dis[2];
  l[0]->get_status(lift_dir[0], lift_locs[0]);
  l[1]->get_status(lift_dir[1], lift_locs[1]);
  for (uint i = 0; i < 2; i++) {
    if (dir == 1) {
      if (lift_dir[i] == 0) {
        lift_dis[i] = abs(floor_no, lift_locs[i]);
      } else if (lift_dir[i] == -1) {
        lift_dis[i] = (floor_no + lift_locs[i]);
      } else { // lift_dir[i] == 1
        if (lift_locs[i] <= floor_no) {
          lift_dis[i] = floor_no - lift_locs[i];
        } else { // lift_locs[i] > floor_no
          lift_dis[i] = 2 * max_floor - (lift_locs[i] - floor_no);
        }
      }
    } else { // dir == -1
      if (lift_dir[i] == 0) {
        lift_dis[i] = abs(floor_no, lift_locs[i]);
      } else if (lift_dir[i] == 1) {
        lift_dis[i] = 2 * max_floor - (floor_no + lift_locs[i]);
      } else { // lift_dir[i] == -1
        if (lift_locs[i] >= floor_no) {
          lift_dis[i] = lift_locs[i] - floor_no;
        } else { // lift_locs[i] < floor_no
          lift_dis[i] = 2 * max_floor - (floor_no - lift_locs[i]);
        }
      }
    }
  }

  if (lift_dis[0] > lift_dis[1]) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  uint max_floors = 6;
  Lift *lift[2];
  Floor *floors[max_floors + 1];

  lift[0] = new Lift(0, max_floors, 0);
  lift[1] = new Lift(1, max_floors, max_floors);
  for (uint i = 0; i <= max_floors; i++) {
    floors[i] = new Floor(max_floors, i, lift[0], lift[1]);
  }
  lift[0]->assign_floors(floors);
  lift[1]->assign_floors(floors);

  uint pass1[2] = {2, 3}, pass2[2] = {0, 1}, pass3[2] = {5, 6};
  cout << "Start" << endl;

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 0. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 0. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  floors[0]->up(pass1, 2);
  // Expected Output: "Floor 0 pressed up button. Lift 0 is assigned."

  floors[1]->up(pass1, 2);
  // Expected Output: "Floor 1 pressed up button. Lift 0 is assigned."

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 0. Lift opens at Floor 0. Passengers
  // get in with destinations: 2, 3. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 1. Lift opens at Floor 1. Passengers
  // get in with destinations: 2, 3. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 2. Lift opens at Floor 2. Passengers
  // get out."

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 3. Lift opens at Floor 3. Passengers
  // get out."

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 3. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 3. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  floors[0]->down(pass2, 2);
  // Expected Output: "Floor 0 has down button disabled."

  floors[5]->down(pass2, 2);
  // Expected Output: "Floor 5 pressed down button. Lift 1 is assigned."

  floors[2]->up(pass3, 2);
  // Expected Output: "Floor 2 pressed up button. Lift 0 is assigned."

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 3. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 6. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 2. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 5. Lift opens at Floor 5. Passengers
  // get in with destinations: 0, 1. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 2. Lift opens at Floor 2. Passengers
  // get in with destinations: 5, 6. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 4. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 3. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 3. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 4. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 2. "

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 5. Lift opens at Floor 5. Passengers
  // get out."

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 1. Lift opens at Floor 1. Passengers
  // get out."

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 6. Lift opens at Floor 6. Passengers
  // get out."

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 0. Lift opens at Floor 0. Passengers
  // get out."

  lift[0]->move();
  // Expected Output: "Lift 0 is at Floor 6. "

  lift[1]->move();
  // Expected Output: "Lift 1 is at Floor 0. "

  cout << "End" << endl;

  return 0;
}
