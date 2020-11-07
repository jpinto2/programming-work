#include "Rotor.h"
#include "CryptoMachine.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

int main() {
	vector<long> numbers;
	long p;
	char letter;
	CryptoMachine c("rotors.txt");
	
	while (cin >> p) {
    numbers.push_back(p);
		if (cin.get() == '\n') numbers.push_back(0);
	} 
	
	for (int i=0; i<numbers.size(); i++) {
			if (numbers[i] == 0) cout << endl;
			else {
			
			letter = c.code_to_letter(numbers[i]);
			cout << letter;
		}
	}
	return 0;
}


