#include <iostream>
#include <gmpxx.h>

mpz_class f(mpz_class const& n)
{
  if (n % 2 == 0) {
    return n / 2;
  } else {
    return 3 * n + 1;
  }
}

#ifdef DEBUG
#define dout std::cout
#else
class __dout {
public:
  template<typename T>
  friend __dout& operator<<(__dout& target, const T& source);
};
template<typename T>
__dout& operator<<(__dout& d, const T& o) { return d; }
__dout __d__;
#define dout __d__
#endif

int main()
{
  unsigned long long max_chain = 0;
  mpz_class n;
  unsigned long ans;
  for (unsigned long i = 2; i < 1000000; ++i) {
    std::cout << "it. " << i << "\n";
    dout << "(" << i << ", ";
    unsigned long long chain = 1;
    n = i;
    while (n != 1) {
      n = f(n);
      chain += 1;
      dout << n << ", ";
    }
    dout << ") " << chain << "\n";
    if (chain > max_chain) {
      max_chain = chain;
      ans = i;
    }
  }
  dout << "\n";
  std::cout << "Max chain = " << max_chain << "\n";
  std::cout << "Answer    = " << ans << "\n";
}
