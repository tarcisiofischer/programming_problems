#include <iostream>
#include <vector>

int sum_of_divisors(int n)
{
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum;
}

int main()
{
  std::vector<int> sums(10000);
  for (int i = 1; i < 10000; ++i) {
    sums[i] = sum_of_divisors(i);
  }

  int total_sum = 0;
  for (int i = 1; i < 10000; ++i) {
    for (int j = 1; j < 10000; ++j) {
      if (i == j) continue;

      if (sums[i] == j && sums[j] == i) {
        total_sum += i;
        break;
      }
    }
  }

  std::cout << total_sum << "\n";
}
