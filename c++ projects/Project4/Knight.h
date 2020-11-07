#ifndef KNIGHT_H
#define KNIGHT_H
#include "Weapon.h"
#include "Random.h"
#include <iostream>
using namespace std;

class Knight {
  private:
    string name;
    int stamina;
    Weapon weapon_in_hand;
  public:
    Knight(string a, int b, string c, int d, int e);
    void charge();
    bool did_you_hit();
    bool tired();
    void display(bool z);
};
#endif
