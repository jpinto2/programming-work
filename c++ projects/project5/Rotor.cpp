#include<iostream>
#include "Rotor.h"
using namespace std;

Rotor::Rotor(int m, int a) : mult(m), add(a)
{
}

long Rotor::encode(long b) {
  b*=mult;
  b+=add;
	return b;
}

long Rotor::decode(long c) {
  c-=add;
  c/=mult;
	return c;
}


