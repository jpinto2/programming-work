//John Pinto; CSCI111-05; Project 6 Zombie Attack
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include "Weapon.h"
using namespace std;

class Person {
  private:
    string name;
    int evasion;
    int rh;
    int lh;
    Weapon* lhw;
    Weapon* rhw;
    bool bitten;
  public:
    Person(string n, int e, int r, int l);
    bool grab(Weapon* wp);
    string get_name();
    int wield();
    bool are_you_bitten();
    void defense(int av);
    void display();
};
#endif
