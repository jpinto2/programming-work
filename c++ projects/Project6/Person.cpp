//John Pinto; CSCI111-05; Project 6 Zombie Attack
#include<iostream>
#include "Person.h"
using namespace std;

Person::Person(string n, int e, int r, int l) : name(n), evasion(e), rh(r), lh(l), rhw(NULL), lhw(NULL), bitten(false)
{
}

string Person::get_name() {
  return name;
}

bool Person::grab(Weapon* wp) {
  int sr=(*wp).get_strength();
  if (rhw==NULL && rh>=sr) {
    rhw=wp;
    return true;
  }
  else if (lhw==NULL && lh>=sr) {
    lhw=wp;
    return true;
  }
  else if (rhw==NULL && lhw==NULL && (rh+lh)>=sr) {
    rhw=lhw=wp;
    return true;
  }
  else {
    cout << "Can't take weapon!" << endl;
    return false;
  }
}

void Person::display() {
  cout << "  Name:       " << name << endl;
  cout << "  Evasion:  " << evasion << endl;
  cout << "  RH str : " << rh << endl;
  cout << "  LH str : " << lh << endl;
  cout << "In right hand: ";
  if (rhw==NULL) cout<< "empty" << endl;
  else {
    cout << endl;
    (*rhw).display();
  }
  cout << "In left hand: ";
  if (lhw==NULL) cout << "empty" << endl;
  else {
    cout << endl;
    (*lhw).display();
  }
  cout << endl;
}

int Person::wield() {
  int sum=rh+lh;
  if (rhw!=NULL) sum+=(*rhw).use();
  if (lhw!=NULL && lhw!=rhw) sum+=(*lhw).use();
  return sum;	
}

bool Person::are_you_bitten() {
  return bitten;
}

void Person::defense(int av) {
  if (av>evasion) {
    bitten=true;
    lhw=rhw=NULL;
  }
}

