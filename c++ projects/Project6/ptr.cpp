#include<iostream>
using namespace std;

class Weapon {
  public:
    void somefunc();
};

void Weapon::somefunc()
{
  cout << "hi folks" << endl;
}

int main()
{
  Weapon w;
  w.somefunc();
  Weapon* wp;
  wp=&w;
  (*wp).somefunc();
  wp->somefunc();
//  (4 + 5) * 10
//  4 + 4 + 4 + 4 + 4;
//  4 * 5
  return 0;
}

