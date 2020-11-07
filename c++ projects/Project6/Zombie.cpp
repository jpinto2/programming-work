//John Pinto; CSCI111-05; Project 6 Zombie Attack
#include<iostream>
#include "Zombie.h"
using namespace std;

Zombie::Zombie(string n, int h, int a) : name(n), attack(a)
{
  Random r(1,h);
  health=r.get();
}

void Zombie::damaged(int d) {
  health-=d;
}

int Zombie::bite() {
  Random r(1,attack);
  int a = r.get();
  return a;
}

bool Zombie::still_up() {
  if (health>0) return true;
  else return false;
}


