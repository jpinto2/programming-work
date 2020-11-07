private:
  vector<Zombie> horde;


//in ZCS::attack
//vector of People: group
//vector of Zombie: horde

while(group.size() > 0 && horde.size() > 0)
{
  //Create Zombie z & Person p from group and horde
  //be sure to erase first item from group and horde once
  //you've assigned them to z & p
  while( z.still_standing() && !p.are_you_bitten() )
  {
    int dam;
    dam=p.wield();
    z.take_damage(dam);
    if(z.still_standing())
    {
      int bite_severity;
      bite_severity=z.bite();
      p.defend_yourself(bite_severity);
    }
  }
  //if the zombie is not still standing, push player on back of 
  //  group vector
  //if the player has been bitten
  //  Create a new zombie from the player:
  //  push both new zombie and zombie Z bon the back of
  //  the horde vector
  //
}
