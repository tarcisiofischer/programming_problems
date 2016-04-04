#include <iostream>
#include <array>
#include <gmpxx.h>

int main()
{
  auto a = std::array<std::array<mpz_class, 21>, 21>();
  for (int i = 0; i < 21; ++i) {
    a[20][i] = 1;
    a[i][20] = 1;
  }

  for (int i = 19; i >= 0; --i) {
    for (int j = 19; j >= 0; --j) {
      a[i][j] = a[i + 1][j] + a[i][j + 1];
    }
  }

  for (int i = 0; i < 21; ++i) {
    for (int j = 0; j < 21; ++j) {
      std::cout << a[i][j] << " ";
    }
    std::cout << "\n";
  }
}
