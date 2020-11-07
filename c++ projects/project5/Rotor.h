#ifndef ROTOR_H
#define ROTOR_H
#include<iostream>
using namespace std;

class Rotor {
	private:
		int mult;
		int add;
	public:
		Rotor(int m, int a);
		long encode(long b);
		long decode(long c);
};
#endif
