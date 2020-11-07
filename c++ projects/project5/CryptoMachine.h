#ifndef CRYPTOMACHINE_H
#define CRYPTOMACHINE_H
#include<iostream>
#include<string>
#include<vector>
#include "Rotor.h"
using namespace std;

class CryptoMachine {
	private:
		vector<Rotor> r;
	public:
		CryptoMachine(string fname);
		long letter_to_code(char b);
		char code_to_letter(long c);
};
#endif
