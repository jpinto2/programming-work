//John Pinto; CSCI111-05; Project 6 Zombie Attack
#ifndef ZCS_H
#define ZCS_H
#include<iostream>
#include<vector>
#include "Weapon.h"
#include "Person.h"
#include "Zombie.h"
using namespace std;

class ZCS {
  private:
    vector<Person> group;
    vector<Zombie> horde;
    vector<Weapon> cache;
  public:
    void add_weapon(Weapon a);
    void add_person(Person b);
    void add_zombie(Zombie c);
    void group_display();
    void assign_weapons();
    void combat();

};
#endif
