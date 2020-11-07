//John Pinto; CSCI111-05; Project 6 Zombie Attack
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Random.h"
using namespace std;

class Weapon {
  private:
    string type;
    int strength;
    int damage;
    int uses;
  public:
    Weapon(string t, int s, int d, int u);
    int get_strength();
    void display();
    int use();
};

class Zombie {
  private:
    string name;
    int health;
    int attack;
  public:
    Zombie(string n, int h, int a);
    void damaged(int d);
    int bite();
    bool still_up();
};

class Person {
  private:
    string name;
    int evasion;
    int rh;
    int lh;
    Weapon* lhw;
    Weapon* rhw;
    bool bitten;
  public:
    Person(string n, int e, int r, int l);
    bool grab(Weapon* wp);
    string get_name();
    int wield();
    bool are_you_bitten();
    void defense(int av);
    void display();
};


class ZCS {
  private:
    vector<Person> group;
    vector<Zombie> horde;
    vector<Weapon> cache;
  public:
    void add_weapon(Weapon a);
    void add_person(Person b);
    void add_zombie(Zombie c);
    void group_display();
    void assign_weapons();
    void combat();

};



Weapon::Weapon(string t, int s, int d, int u) : type(t), strength(s), damage(d), uses(u)
{
}

int Weapon::get_strength() {
  return strength;
}

void Weapon::display() {
  cout << "===" << endl;
  cout << "  Type:       " << type << endl;
  cout << "  Str. Reqd:  " << strength << endl;
  cout << "  Dmg. Bonus: " << damage << endl;
  cout << "  Use Remain: " << uses << endl;
}

int Weapon::use() {
  if (uses>0) {
    uses--;
    return damage;
  }
  else return 0;
}

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

Zombie::Zombie(string n, int h, int a) : name(n), attack(a)
{
  Random r(1,h);
  health=r.get();
}

void Zombie::damaged(int d) {
  health-=d;
}

int Zombie::bite() {
  Random r(1,attack);
  int a = r.get();
  return a;
}

bool Zombie::still_up() {
  if (health>0) return true;
  else return false;
}

void ZCS::add_weapon(Weapon a) {
  cache.push_back(a);
}

void ZCS::add_person(Person b) {
  group.push_back(b);
}

void ZCS::add_zombie(Zombie c) {
  horde.push_back(c);
}

void ZCS::group_display() {
  cout << "The group:" << endl;
  for(int i=0; i<group.size(); i++) group[i].display();
}

void ZCS::assign_weapons() {
  int i, j;
  int choice;
  string n;
  bool z;
  for(i=0;i<cache.size(); i++) {
    z=false;
    do {
      cache[i].display();
      cout << "Who should get this weapon?" << endl;
      for(j=0;j<group.size(); j++) {
        cout << j << ") ";
        n=group[j].get_name();
        cout << n << endl;
      }
      cout << group.size() << ") Nobody" << endl;
      cin >> choice;
      if (choice == group.size()) z=true;
      else z=group[choice].grab(&cache[i]);
    } while(z==false);
  }
}

void ZCS::combat() {
    int dm;
    cout << "Number of zombies: " << horde.size() << endl;
    cout << "Number of survivors: " << group.size() << endl;
    cout << "LET THE COMBAT BEGIN!" << endl;
    while (group.size()!=0 && horde.size()!=0) {
      Person p = group[0];
      Zombie z = horde[0];
      group.erase(group.begin());
      horde.erase(horde.begin());
      bool done = false;
      while (!done) {
        z.damaged(p.wield());

        if(!z.still_up()) {
          done = true;
          group.push_back(p);
          cout << p.get_name() << " kills Zombie!" << endl;
        }

        else {
          p.defense(z.bite());
          if (p.are_you_bitten()) {
            done = true;
            Zombie y(p.get_name(), p.wield(), p.wield());
            horde.push_back(z);
            horde.push_back(y);
            cout << p.get_name() << " has been bitten!" << endl;
          }
        }

      }
      cout << "Number of zombies: " << horde.size() << endl;
      cout << "Number of survivors: " << group.size() << endl;
    }
}


int main() {
  ifstream inf1, inf2, inf3;
  ZCS sim;
  string ty;
  int st, dm, us;
  string na;
  int ev, ri, le;
  int he, at;

  inf1.open("cache.txt");
  while (!getline(inf1, ty, '|').eof()) {

    inf1 >> st;
    inf1.ignore();
    inf1 >> dm;
    inf1.ignore();
    inf1 >> us;
    inf1.ignore();
    Weapon c(ty, st, dm, us);
    sim.add_weapon(c);
  }
  inf1.close();

  inf2.open("group.txt");
  while (!getline(inf2, na, '|').eof()) {

    inf2 >> ev;
    inf2.ignore();
    inf2 >> ri;
    inf2.ignore();
    inf2 >> le;
    inf2.ignore();
    Person d(na, ev, ri, le);
    sim.add_person(d);
  }
  inf2.close();

  inf3.open("horde.txt");
  while (!getline(inf3, na, '|').eof()) {

    inf3>> he;
    inf3.ignore();
    inf3 >> at;
    inf3.ignore();
    Zombie e(na, he, at);
    sim.add_zombie(e);
  }
  inf3.close();  

  sim.assign_weapons();
  sim.group_display();
  sim.combat();
  cout << endl;
  return 0;
}
