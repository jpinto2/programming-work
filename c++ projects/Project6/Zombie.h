//John Pinto; CSCI111-05; Project 6 Zombie Attack
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include<iostream>
#include "Random.h"
using namespace std;

class Zombie {
  private:
    string name;
    int health;
    int attack;
  public:
    Zombie(string n, int h, int a);
    void damaged(int d);
    int bite();
    bool still_up();
};
#endif

