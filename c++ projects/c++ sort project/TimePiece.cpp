//Version 1.0
#include"TimePiece.h"
#include<iomanip>
TimePiece::TimePiece(void) : hours(0), minutes(0)
{ }

bool TimePiece::operator<=(const TimePiece& rhs) const
{
  return hours*60+minutes <= rhs.hours*60+rhs.minutes;
}

bool TimePiece::operator>=(const TimePiece& rhs) const
{
  return hours*60+minutes >= rhs.hours*60+rhs.minutes;
}

bool TimePiece::operator<(const TimePiece& rhs) const
{
  return hours*60+minutes < rhs.hours*60+rhs.minutes;
}

bool TimePiece::operator>(const TimePiece& rhs) const
{
  return hours*60+minutes > rhs.hours*60+rhs.minutes;
}

bool TimePiece::operator==(const TimePiece& rhs) const
{
  return hours*60+minutes == rhs.hours*60+rhs.minutes;
}

std::ostream& operator<<(std::ostream& os, TimePiece& tp)
{
  return os << std::setfill('0') << std::setw(2) << tp.hours << ':' << std::setw(2) << tp.minutes << std::setfill(' ');
}

std::istream& operator>>(std::istream& is, TimePiece& tp)
{
  int temp;
  is >> temp;
  tp.hours=temp/60;
  tp.minutes=temp%60;
  return is;
}
