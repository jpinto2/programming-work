#include "Rotor.h"
#include "CryptoMachine.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


int main() {
	vector<string> phrases;
	string p;
	long n;
	CryptoMachine c("rotors.txt");
	
	while (getline(cin, p)) {
		phrases.push_back(p);
	} 
	
	for (int i=0; i<phrases.size(); i++) {
		
		for (int j=0; j<phrases[i].size(); j++) {
			
			n = c.letter_to_code(phrases[i][j]);
			cout << n << " ";
			
		}
		
		cout << endl;
	}
	return 0;
}


