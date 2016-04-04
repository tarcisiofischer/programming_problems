#include <iostream>
#include <map>
#include <string>
#include <gmpxx.h>

#define INSERT(X, Y) n_to_str.insert(std::pair<int, std::string>(X, Y))

std::string int_to_str(int i)
{
  std::map<int, std::string> n_to_str;
  INSERT(1, "one");
  INSERT(2, "two");
  INSERT(3, "three");
  INSERT(4, "four");
  INSERT(5, "five");
  INSERT(6, "six");
  INSERT(7, "seven");
  INSERT(8, "eight");
  INSERT(9, "nine");
  INSERT(10, "ten");
  INSERT(11, "eleven");
  INSERT(12, "twelve");
  INSERT(13, "thirteen");
  INSERT(14, "fourteen");
  INSERT(15, "fifteen");
  INSERT(16, "sixteen");
  INSERT(17, "seventeen");
  INSERT(18, "eighteen");
  INSERT(19, "nineteen");
  INSERT(20, "twenty");
  INSERT(30, "thirty");
  INSERT(40, "forty");
  INSERT(50, "fifty");
  INSERT(60, "sixty");
  INSERT(70, "seventy");
  INSERT(80, "eighty");
  INSERT(90, "ninety");
  INSERT(100, "one hundred");
  INSERT(1000, "one thousand");

  if (n_to_str.find(i) != n_to_str.end()) {
    return n_to_str[i];
  }

  std::string r = "";
  if (i > 100) {
    int hs = 100 * (i / 100);
    int ts = 10 * ((i - hs) / 10);
    int us = i - ts - hs;
    r += n_to_str[hs / 100];
    r += " hundred";
    if (ts == 0) {
      if (us != 0) {
        r += " and ";
        r += n_to_str[us];
      }
    } else if (ts == 10) {
      r += " and ";
      r += n_to_str[(i - hs)];
    } else {
      r += " and ";
      r += n_to_str[ts];
      r += " ";
      r += n_to_str[us];
    }
  } else if (i > 20) {
    int ts = 10 * (i / 10);
    int us = i - ts;
    r += n_to_str[ts];
    r += " ";
    r += n_to_str[us];
  }

  return r;
}

mpz_class count_letters(std::string const& s)
{
  mpz_class size = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != ' ') {
      ++size;
    }
  }
  return size;
}

int main()
{
  mpz_class total = 0;
  for (int i = 1; i <= 1000; ++i) {
    total += count_letters(int_to_str(i));
  }
  std::cout << total << "\n";
}






