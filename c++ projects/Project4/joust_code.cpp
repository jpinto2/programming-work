class Report {
  private:
    string rep_desc;
    Date rep_date; //"has-a" relationship, aka "composition"
    Time rep_time; //"has-a" relationship, aka "composition"
};

class Weapon {
  ...
  private:
    int stamina_required;
  public:
    int get_stamina_required();
}; 

bool Weapon::did_you_hit()
{
  Random r(1,100);
  int rn;
  rn=r.get();
}


int Weapon::get_stamina_required()
{
  return stamina_required;
}

class Knight {
  private:
    string name;
    int stamina;
    Weapon weapon_in_hand;
  public:
    bool charge();
};

bool Knight::charge()
{
  int temp;
  temp=weapon_in_hand.get_stamina_required();
  stamina-=temp;
}



while(4 questions)
{
  charge
  k1.display();
  k2.display();
}
