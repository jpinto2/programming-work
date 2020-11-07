#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
using namespace std;

class Weapon {
  private:
    int stamina_required;
    int hit;
    string weapon_name; 
  public:
    Weapon(string a, int b, int c);
    string get_weapon_name();
    int get_stamina_required();
    int get_hit();
};
#endif 
