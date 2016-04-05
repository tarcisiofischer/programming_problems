#include <gmpxx.h>
#include <iostream>

int main()
{
  mpz_class n = 1;
  for (int i = 2; i < 100; ++i) {
    n *= i;
  }

  std::string s = n.get_str();
  mpz_class r = 0;
  for (int i = 0; i < s.size(); ++i) {
    r += s[i] - '0';
  }
  std::cout << r << "\n";
}
