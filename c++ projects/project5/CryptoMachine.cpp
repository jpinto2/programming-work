#include "CryptoMachine.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

CryptoMachine::CryptoMachine(string fname)  {
	int M;
	int A;
	
	ifstream inf(fname.c_str());
	while (!inf.eof()) {
		inf>>M>>A;
		Rotor ro(M,A);
		r.push_back(ro);
	}
	inf.close();
}

long CryptoMachine::letter_to_code(char b) {
	long n; 
	n=b;
	for (int i=0; i<r.size(); i++) n = r[i].encode(n);
	return n;
}

char CryptoMachine::code_to_letter(long c) {
	char l;
	for (int i=0; i<r.size(); i++) c = r[r.size()-i-1].decode(c);
	l=c;
	return l;
}

