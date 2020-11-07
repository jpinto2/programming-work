#include<iostream>
using namespace std;
int main()
{
  string name;
  int age;
  float gpa;
  string kn;
  int ks;
  string wt;
  //for creating a knight you need: 
  // 1 knight's name,
  // 2 knight's stamina
  // 3 Type of weapon (e.g., "Lance")
  // 4 weapon's stamina required
  // 5 weapon's hit chance
  float x=3.14;
  Knight k1(kn, ks, wt,  [2 more arguments go here]);
  //ask 5 questions
  Knight k2(kn, ks, wt,  [2 more arguments go here]);
  cout << "What is your name?";
  cin >> name;
  cout << "What is your age?";
  cin >> age;
  cout << "What is your gpa?";
  cin >> gpa;
  //Create a student
  cout << "Creating student: " << name << ", " << age << ", " << gpa << endl;
  cout << "What is your name?";
  cin >> name;
  cout << "What is your age?";
  cin >> age;
  cout << "What is your gpa?";
  cin >> gpa;
  cout << "Creating student: " << name << ", " << age << ", " << gpa << endl;
  //Create another student

  return 0;
}
