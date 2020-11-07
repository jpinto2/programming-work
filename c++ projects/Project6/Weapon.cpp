//John Pinto; CSCI111-05; Project 6 Zombie Attack
#include<iostream>
#include "Weapon.h"
using namespace std;

Weapon::Weapon(string t, int s, int d, int u) : type(t), strength(s), damage(d), uses(u)
{
}

int Weapon::get_strength() {
  return strength;
}

void Weapon::display() {
  cout << "===" << endl;
  cout << "  Type:       " << type << endl;
  cout << "  Str. Reqd:  " << strength << endl;
  cout << "  Dmg. Bonus: " << damage << endl;
  cout << "  Use Remain: " << uses << endl;
}

int Weapon::use() {
  if (uses>0) {
    uses--;
    return damage;
  }
  else return 0;
}


