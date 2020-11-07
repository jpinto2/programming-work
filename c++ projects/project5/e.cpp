#include<iostream>
#include<string>
#include<vector>
#include<fstream>
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

class CryptoMachine {
	private:
		vector<Rotor> r;
	public:
		CryptoMachine(string fname);
		long letter_to_code(char b);
		char code_to_letter(long c);
};

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

CryptoMachine::CryptoMachine(string fname)  {
	int M;
	int A;
	ifstream inf(fname.c_str());
	while (!inf.eof()) {
		inf >> M >> A;
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
	for (int i=0; i<r.size(); i++) c = r[i].decode(c);
	l=c;
	return l;
}

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


