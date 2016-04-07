#include <iostream>
#include <vector>
#include <tuple>

int sum_of_prop_divisors(int n)
{
  int sum = 0;
  for (int i = 1; i < n; ++i)
    if (n % i == 0)
      sum += i;
  return sum;
}

std::pair<std::vector<bool>, std::vector<int>> compute_abundant_numbers(int n)
{
  std::vector<bool> is_abundant(n + 1);
  is_abundant[0] = false;
  std::vector<int> abundant_numbers;
  for (int i = 1; i <= n; ++i) {
    is_abundant[i] = (sum_of_prop_divisors(i) > i);
    if (is_abundant[i]) {
      abundant_numbers.push_back(i);
    }
  }
  return std::pair<std::vector<bool>, std::vector<int>>(is_abundant, abundant_numbers);
}

int main()
{
  std::vector<bool> is_abundant;
  std::vector<int> abundant_numbers;
  tie(is_abundant, abundant_numbers) = compute_abundant_numbers(28123);

  int sum = 0;
  for (int i = 1; i < 28123; ++i) {
    bool can_be_written_as_sum_of_abundants = false;
    for (auto n = abundant_numbers.begin(); n < abundant_numbers.end(); ++n) {
      if (*n > i) break;
      if (is_abundant[i - *n]) {
        can_be_written_as_sum_of_abundants = true;
        break;
      }
    }
    if (!can_be_written_as_sum_of_abundants) {
      sum += i;
    }
  }

  std::cout << sum << "\n";
}
