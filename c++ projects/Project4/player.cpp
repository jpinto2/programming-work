int Player::roll()
{
  Random r(1,12);
  int rn=r.get();
  return rn;
  
}
