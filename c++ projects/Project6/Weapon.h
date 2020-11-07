//John Pinto; CSCI111-05; Project 6 Zombie Attack
#ifndef WEAPON_H
#define WEAPON_H
#include<iostream>
using namespace std;

class Weapon {
  private:
    string type;
    int strength;
    int damage;
    int uses;
  public:
    Weapon(string t, int s, int d, int u);
    int get_strength();
    void display();
    int use();
};
#endif
