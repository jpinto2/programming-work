#include "Random.h"
#include<iostream>
using namespace std;
int main()
{
  Random r(1,100);
  int rn=r.get();
  cout << rn << endl;
  rn=r.get();
  cout << rn << endl;
  rn=r.get();
  cout << rn << endl;
  return 0;
}
