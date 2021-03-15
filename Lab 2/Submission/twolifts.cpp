/**
 * Author: Devansh Jain (190100044)
 * Lab 2 - Two Lifts
 */

#include <iostream>
#include <list>

using namespace std;

class Lift;
class Floor;

class Lift {
private:
  uint current_loc;
  uint max_floor;
  bool *up_wait, *down_wait, *dest_list;
  int dir;
  Floor **f;

public:
  Lift(uint n, uint start);
  void assign_floors(Floor *floors[]);
  void up(uint floor_no);
  void down(uint floor_no);
  void move();
  bool open();
  int get_dir();
};

class Floor {
private:
  uint floor_no;
  uint max_floor;
  list<uint> waiting_up, waiting_down;
  Lift *l;

public:
  Floor(uint n, uint i, Lift *lift);
  void up(uint dest[], uint k);
  void down(uint dest[], uint k);
  list<uint> lift_opens(bool dir);
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
  cout << "Lift is at Floor " << current_loc << endl;

  if (open()) {
    list<uint> pass = f[current_loc]->lift_opens(dir);
    for (auto it : pass) {
      dest_list[it] = true;
    }
  }
  dest_list[current_loc] = false;

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
      if (up_wait[i]) {
        dir = 1;
        break;
      }
      if (down_wait[i]) {
        dir = -1;
        break;
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

bool Lift::open() {
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

int Lift::get_dir() { return dir; }

Floor::Floor(uint n, uint i, Lift *lift) {
  max_floor = n;
  floor_no = i;
  l = lift;
}

void Floor::up(uint dest[], uint k) {
  if (floor_no == max_floor) {
    cout << "Floor " << floor_no << " has up button disabled" << endl;
    return;
  }
  for (int i = 0; i < k; i++) {
    if (dest[i] <= max_floor && dest[i] != floor_no) {
      waiting_up.push_back(dest[i]);
    }
  }
  l->up(floor_no);
}

void Floor::down(uint dest[], uint k) {
  if (floor_no == 0) {
    cout << "Floor " << floor_no << " has down button disabled" << endl;
    return;
  }
  for (int i = 0; i < k; i++) {
    if (dest[i] <= max_floor && dest[i] != floor_no) {
      waiting_down.push_back(dest[i]);
    }
  }
  l->down(floor_no);
}

list<uint> Floor::lift_opens(bool dir) {
  list<uint> pass;
  if (dir == 1) {
    pass = waiting_up;
    waiting_up.clear();
  }
  if (dir == -1) {
    pass = waiting_down;
    waiting_down.clear();
  }
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
  cout << "Part1" << endl;
  floors[0]->up(pass1, 2);
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  cout << "Part2" << endl;
  floors[0]->down(pass2, 2);
  floors[4]->up(pass3, 2);
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  lift->move();
  cout << "End" << endl;

  return 0;
}
