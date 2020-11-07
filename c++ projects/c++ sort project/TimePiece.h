// Version 1.0
#ifndef TIMEPIECE_H
#define TIMEPIECE_H
#include<iostream>
class TimePiece {
  public:
    TimePiece();
    bool operator<(const TimePiece&) const;
    bool operator>(const TimePiece&) const;
    bool operator<=(const TimePiece&) const;
    bool operator>=(const TimePiece&) const;
    bool operator==(const TimePiece&) const;
  private:
    int hours;
    int minutes;

    friend std::ostream& operator<<(std::ostream&, TimePiece&);
    friend std::istream& operator>>(std::istream&, TimePiece&);
};
#endif
