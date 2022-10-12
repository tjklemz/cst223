#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

int main() {
  std::vector<int> nums{1, 2, 3, 4, 5};
  std::mt19937 rand{std::random_device{}()};
  std::shuffle(nums.begin(), nums.end(), rand);

  for (auto n : nums) {
    std::cout << n << '\n';
  }
}
