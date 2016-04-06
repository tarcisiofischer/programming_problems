#include <gmpxx.h>
#include <iostream>

int main()
{
  mpz_class f, g, h;
  f = 1;
  g = 1;
  for (mpz_class i = 3; ; ++i) {
    h = f + g;
    
    if (h.get_str().size() == 1000) {
      std::cout << i << "\n";
      break;
    }

    f = g;
    g = h;
  }
}
