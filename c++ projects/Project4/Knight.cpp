#include "Knight.h"
#include <iostream>
using namespace std;

Knight::Knight(string a, int b, string c, int d, int e) : name(a), stamina(b), weapon_in_hand(c, d, e)
{
}

void Knight::charge()
{
  int temp;
  temp=weapon_in_hand.get_stamina_required();
  stamina-=temp;
}

bool Knight::did_you_hit()
{
  Random r(1,100);
  int rn, h;
  rn=r.get();
  h=weapon_in_hand.get_hit();
  return (rn<=h);
}

bool Knight::tired()
{
  return (stamina<=0);
}

void Knight::display(bool z)
{
  cout << name << " is ";
  if (stamina>0) cout << "not ";
  cout << "exhausted (stamina=" << stamina << ") and ";
  if (z) cout << "has been knocked off of the horse" << endl;
  else cout << "is still on the horse" << endl;
  cout << name << " is using: " << weapon_in_hand.get_weapon_name() << " that requires ";
  cout << weapon_in_hand.get_stamina_required() << " stamina and has a ";
  cout << weapon_in_hand.get_hit() << "% chance to hit" << endl;

}
