// John Pinto; CSCI111-05; Project 4: Joust

#include "Random.h"
#include "Weapon.h"
#include "Knight.h"
#include<iostream>
using namespace std;

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

