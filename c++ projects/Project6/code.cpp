 class Person {
   string name;
   Weapon* rhw;
   Weapon* lhw;
 };

Knight::Knight(x5) : ...., on_horse(true)

Person::Person(...) : ..., rhw(NULL), lhw(NULL)

Person::grab(Weapon* candidate_weap)
{
  if(rhw==NULL)
    cout << "Todd has no Weapon in his right hand"
}
