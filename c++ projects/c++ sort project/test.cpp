#include<iostream>
#include"TimePiece.h"
using namespace std;
int main()
{
  TimePiece p,q;
  cin >> p >> q;
  cout << "p=" << p << ", q=" << q << endl;
  if( p > q)
    cout << "P is greater than Q" << endl;
  else if (q > p)
    cout << "Q is greater than P" << endl;
  else
    cout << "They are equal" <<endl;
  return 0;
}
