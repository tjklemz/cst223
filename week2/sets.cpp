#include <vector>
#include <iostream>
#include <algorithm>

int main() {
  std::vector<int> a{1, 2, 3, 4};
  std::vector<int> b{2, 3, 5};
  std::vector<int> c{};

  std::set_intersection(
    a.begin(), a.end(),
    b.begin(), b.end(),
    std::back_inserter(c)
  );

  for (auto n : c) {
    std::cout << n << '\n';
  }
}
