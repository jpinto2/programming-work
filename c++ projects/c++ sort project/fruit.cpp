#include<iostream>
using namespace std;
class Fruit {
};

class Apple : public Fruit {
};

class Banana : public Fruit {
};

class Kiwi : public Fruit {
};

int main()
{
  Fruit* give_it_a_name;
  cout << "which fruit would you like? 1) Apple, 2) Banana, 3) Kiwi" << endl;
  int choice;
  cin >> choice;
  switch(choice)
  {
    case 1:
      give_it_a_name=new Apple;
      break;
      ///...
    case 3:
      cout << "Ah, a connoisseur of fruit I see" <<endl;
      give_it_a_name=new Kiwi;

  }
return 0;
}
