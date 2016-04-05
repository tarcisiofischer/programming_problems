#include <iostream>
#include <map>
#include <vector>
#include <iostream>

bool is_leap(int year)
{
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return true;
      }
      return false;
    }
    return true;
  }
  return false;
}

int days_on_month(int year, int month)
{
  std::map<int, int> months;
  #define ADD_MONTH(X, Y) months.insert(std::pair<int, int>(X, Y))
  ADD_MONTH(1, 31); // Jan
  ADD_MONTH(2, 28); // Feb
  ADD_MONTH(3, 31); // Mar
  ADD_MONTH(4, 30); // Apr
  ADD_MONTH(5, 31); // May
  ADD_MONTH(6, 30); // Jun
  ADD_MONTH(7, 31); // Jul
  ADD_MONTH(8, 31); // Aug
  ADD_MONTH(9, 30); // Sep
  ADD_MONTH(10, 31);// Oct
  ADD_MONTH(11, 30);// Nov
  ADD_MONTH(12, 31);// Dec
  if (month == 2 && is_leap(year)) {
    return months[month] + 1;
  }
  return months[month];
}

class Date {
public:
  Date(int day, int month, int year) : _day(day), _month(month), _year(year) {};

  Date& operator+=(int i) { // Will not work with big i's
    this->_day += i;
    int max_days = days_on_month(this->_year, this->_month); 
    if (this->_day > max_days) {
      this->_day -= max_days;
      ++this->_month;
    }
    if (this->_month > 12) {
      this->_month = 1;
      ++this->_year;
    }
    return *this;
  }

  bool operator<=(const Date& other) {
    return this->_day <= other._day &&
      this->_month <= other._month &&
      this->_year <= other._year;
  }

  const int& day() { return this->_day; }
  friend std::ostream& operator<<(std::ostream& o, const Date& d);

private:
  int _day;
  int _month;
  int _year;
};

std::ostream& operator<<(std::ostream& o, const Date& d) {
  o << d._day << "/" << d._month << "/" << d._year << "\n";
  return o;
}

int main()
{
  int result = 0;
  Date first_sunday(6, 1, 1901); // First sunday
  Date last_day(31, 12, 2000);
  for (Date date = first_sunday; date <= last_day; date += 7)
    if (date.day() == 1)
      ++result;
  std::cout << result << "\n";
}

