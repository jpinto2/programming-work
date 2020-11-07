//John Pinto; CSCI111-05; Project 6 Zombie Attack
#include<iostream>
#include<string>
#include<fstream>
#include "Zombie.h"
#include "Person.h"
#include "Weapon.h"
#include "ZCS.h"
using namespace std;

int main() {
  ifstream inf1, inf2, inf3;
  ZCS sim;
  string ty;
  int st, dm, us;
  string na;
  int ev, ri, le;
  int he, at;

  inf1.open("cache.txt");
  while (!getline(inf1, ty, '|').eof()) {

    inf1 >> st;
    inf1.ignore();
    inf1 >> dm;
    inf1.ignore();
    inf1 >> us;
    inf1.ignore();
    Weapon c(ty, st, dm, us);
    sim.add_weapon(c);
  }
  inf1.close();

  inf2.open("group.txt");
  while (!getline(inf2, na, '|').eof()) {

    inf2 >> ev;
    inf2.ignore();
    inf2 >> ri;
    inf2.ignore();
    inf2 >> le;
    inf2.ignore();
    Person d(na, ev, ri, le);
    sim.add_person(d);
  }
  inf2.close();

  inf3.open("horde.txt");
  while (!getline(inf3, na, '|').eof()) {

    inf3>> he;
    inf3.ignore();
    inf3 >> at;
    inf3.ignore();
    Zombie e(na, he, at);
    sim.add_zombie(e);
  }
  inf3.close();  

  sim.assign_weapons();
  sim.group_display();
  sim.combat();
  cout << endl;
  return 0;
}
