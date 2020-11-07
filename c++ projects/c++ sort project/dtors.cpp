class Base {
  public:
    virtual ~Base(){};
  private:
    string bstr;
};


class Derived : public Base {
  ~Derived();
  private:
  string dstr;
};


Base* bp;
bp = new Derived;

string s="Todd";
s = s + "Gibson";

delete bp;






