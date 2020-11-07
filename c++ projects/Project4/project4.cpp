#include<iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
using namespace std;

class Random {
  public:
    Random(int low, int high); //constructor
    int get(void) const;
  private:
    int low;
    int diff;
    static void seed(void);
    static int seedcount;
};

class Weapon {
  private:
    int stamina_required;
    int hit;
    string weapon_name; 
  public:
    Weapon(string a, int b, int c);
    string get_weapon_name();
    int get_stamina_required();
    int get_hit();
}; 

class Knight {
  private:
    string name;
    int stamina;
    Weapon weapon_in_hand;
  public:
    Knight(string a, int b, string c, int d, int e);
    void charge();
    bool did_you_hit();
    bool tired();
    void display(bool z);
};

int Random::seedcount=0;

void Random::seed(void)
{
  if(seedcount) return; //we only want to seed once
  seedcount=1;
  srand((int)time(0)); //seeds the random number generator
}

Random::Random(int l, int h) : low(l), diff(abs(h-l)+1)
{
  seed();
}

int Random::get(void) const
{
  return int((float)rand()/RAND_MAX*diff+low);
}

Weapon::Weapon(string a, int b, int c) : weapon_name(a), stamina_required(b), hit(c)
{
}

string Weapon::get_weapon_name()
{
  return weapon_name;
}

int Weapon::get_stamina_required()
{
  return stamina_required;
}

int Weapon::get_hit()
{
  return hit;
}

Knight::Knight(string a, int b, string c, int d, int e) : name(a), stamina(b), weapon_in_hand(c, d, e)
{
}

void Knight::charge()
{
  int temp;
  temp=weapon_in_hand.get_stamina_required();
  stamina-=temp;
}

bool Knight::did_you_hit()
{
  Random r(1,100);
  int rn, h;
  rn=r.get();
  h=weapon_in_hand.get_hit();
  return (rn<=h);
}

bool Knight::tired()
{
  return (stamina<=0);
}

void Knight::display(bool z)
{
  cout << name << " is ";
  if (stamina>0) cout << "not ";
  cout << "exhausted (stamina=" << stamina << ") and ";
  if (z) cout << "has been knocked off of the horse" << endl;
  else cout << "is still on the horse" << endl;
  cout << name << " is using: " << weapon_in_hand.get_weapon_name() << " that requires ";
  cout << weapon_in_hand.get_stamina_required() << " stamina and has a ";
  cout << weapon_in_hand.get_hit() << "% chance to hit" << endl;

}

int main()
{
  string kname, wname; // knight name,, weapon name
  int ks, ws, p; // knight stamina, weapon stamina, probability to hit

  bool lose1 = false; // neither knight has lost yet
  bool lose2 = false;

  cout << "Welcome to the Joust. You will select the stats for two knights and see which one triumphs!" << endl;
  cout << "What is the first knight's name: ";
  cin >> kname;
  cout << "How much stamina does the knight have: ";
  cin >> ks;
  cout << "What type of weapon does the knight use: ";
  cin >> wname;
  cout << "How much stamina is required to use the weapon: ";
  cin >> ws;
  cout << "What is the percent probability for the weapon to hit: ";
  cin >> p;
  Knight k1(kname, ks, wname, ws, p);

  cout << "What is the second knight's name: ";
  cin >> kname;
  cout << "How much stamina does the knight have: ";
  cin >> ks;
  cout << "What type of weapon does the knight use: ";
  cin >> wname;
  cout << "How much stamina is required to use the weapon: ";
  cin >> ws;
  cout << "What is the percent probability for the weapon to hit: ";
  cin >> p;
  Knight k2(kname, ks, wname, ws, p);	

  do    // The knights are supposed to charge at least once so I use a do-while loop
  {

    k1.charge();  // The both knights charge and their stamina updates
    k2.charge();

    lose2 = k1.did_you_hit(); // If a knight hits, it means a loss for the other knight
    lose1 = k2.did_you_hit();

    k1.display(lose1);  // Displays Status
    k2.display(lose2);

    if (!(lose1 || lose2))  //Only checks if neither knight has been hit
    {
      lose1 = k1.tired(); // If the knight is tired, they are done
      lose2 = k2.tired();
    }
  } while (!(lose1 || lose2));

  return 0;
}

