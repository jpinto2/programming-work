//John Pinto; CSCI111-05; Project 6 Zombie Attack
#include<iostream>
#include<vector>
#include "ZCS.h"
using namespace std;

void ZCS::add_weapon(Weapon a) {
  cache.push_back(a);
}

void ZCS::add_person(Person b) {
  group.push_back(b);
}

void ZCS::add_zombie(Zombie c) {
  horde.push_back(c);
}

void ZCS::group_display() {
  cout << "The group:" << endl;
  for(int i=0; i<group.size(); i++) group[i].display();
}

void ZCS::assign_weapons() {
  int i, j;
  int choice;
  string n;
  bool z;
  for(i=0;i<cache.size(); i++) {
    z=false;
    do {
      cache[i].display();
      cout << "Who should get this weapon?" << endl;
      for(j=0;j<group.size(); j++) {
        cout << j << ") ";
        n=group[j].get_name();
        cout << n << endl;
      }
      cout << group.size() << ") Nobody" << endl;
      cin >> choice;
      if (choice == group.size()) z=true;
      else z=group[choice].grab(&cache[i]);
    } while(z==false);
  }
}

void ZCS::combat() {
    int dm;
    cout << "Number of zombies: " << horde.size() << endl;
    cout << "Number of survivors: " << group.size() << endl;
    cout << "LET THE COMBAT BEGIN!" << endl;
    while (group.size()!=0 && horde.size()!=0) {
      Person p = group[0];
      Zombie z = horde[0];
      group.erase(group.begin());
      horde.erase(horde.begin());
      bool done = false;
      while (!done) {
        z.damaged(p.wield());

        if(!z.still_up()) {
          done = true;
          group.push_back(p);
          cout << p.get_name() << " kills Zombie!" << endl;
        }

        else {
          p.defense(z.bite());
          if (p.are_you_bitten()) {
            done = true;
            Zombie y(p.get_name(), p.wield(), p.wield());
            horde.push_back(z);
            horde.push_back(y);
            cout << p.get_name() << " has been bitten!" << endl;
          }
        }

      }
      cout << "Number of zombies: " << horde.size() << endl;
      cout << "Number of survivors: " << group.size() << endl;
    }
}

