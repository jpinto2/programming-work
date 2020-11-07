#include<iostream>
using namespace std;
class Media {
  public:
    Media(string cn, string ti);
    void display();
  protected:
    string call_number;
    string title;
};

Media::Media(string cn, string ti)
{
  call_number=cn;
  title=ti;
}

class Book : public Media {
  private:
    string author;
    string year;
  public:
    Book(string cn, string ti, string au, string yr);
    void display();
};

Book::Book(string cn, string ti, string au, string yr)
  :Media(cn, ti), author(au), year(yr)
{
//    call_number=cn;
//    title=ti;
//    author=au;
//    year=yr;
}

void Book::display()
{
  cout << "Call_number: " << call_number << endl;
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Year: " << year << endl;
}

class Film : public Media{
  private:
    string director;
    string genre;
    string gross; //money made on film
  public:
    Film(string cn, string ti, string di, string ge, string gr);
    void display();
};

Film::Film(string cn, string ti, string di, string ge, string gr)
  :Media(cn, ti), director(di), genre(ge), gross(gr)
{
}

void Film::display()
{
  cout << "Call_number: " << call_number << endl;
  cout << "Title: " << title << endl;
  cout << "Director: " << director << endl;
  cout << "Genre: " << genre << endl;
  cout << "Gross: $" << gross << endl;
}

int main()
{
  Book bk("Arts 123.52", "The Wind in The Willows", "P.J. Amas", "1947");
  bk.display();
}
