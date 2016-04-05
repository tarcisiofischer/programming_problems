#include <iostream>
#include <vector>

void print_permutation(std::vector<int>& values, int& n, int p, char* perm)
{
  if (values.size() == 1) {
    ++n;
    if (n == 1000000) {
      perm[p] = '0' + values[0];
      std::cout << perm << "\n";
    }
    return;
  }
  
  auto size = values.size();
  for (int i = 0; i < size; ++i) {
    auto tmp = values[i];
    perm[p] = '0' + tmp;
    values.erase(values.begin() + i);
    print_permutation(values, n, p + 1, perm);
    values.insert(values.begin() + i, tmp);
  }
}

int main()
{
  char perm[11];
  perm[10] = 0;
  std::vector<int> values({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  int i = 0;
  print_permutation(values, i, 0, perm);
}
