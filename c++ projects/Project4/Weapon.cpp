#include <iostream>
#include "Weapon.h"
using namespace std;

Weapon::Weapon(string a, int b, int c) : weapon_name(a), stamina_required(b), hit(c)
{
}

string Weapon::get_weapon_name()
{
  return weapon_name;
}

int Weapon::get_stamina_required()
{
  return stamina_required;
}

int Weapon::get_hit()
{
  return hit;
}
