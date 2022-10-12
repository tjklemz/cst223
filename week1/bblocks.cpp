#include <iostream>
#include <vector>
#include <map>
#include <ifstream>

/*

1. Atoms/scalars (single items)
2. Lists (array, std::vector, std::array, std::list)
3. Bags (std::map, std::set, hashmap, hashtable, records, dictionary, key-value storage)
4. Lambdas (first class functions)

*/

int main() {
  int x{5};

  // RAII, gets cleaned up just like the "x" variable, etc, above
  std::ifstream file{"myfile.txt"};

  // array
  int xs[]{1, 2, 3, 4};
  // std::vector
  std::vector<int> ys{1, 2, 3, 4};
  // bags
  std::map<std::string, int> users{{"bob", 42}, {"susan", 23}};
  users["bob"] = 33;

  // lambda
  auto add2 = [](auto x) {
    return x + 2;
  };

  auto result = add2(4);

  auto myFunc = [](auto x) {
    return [=]() {
      return x + 2;
    };
  };

  auto newResult = myFunc(4)();
  auto giveMeNum = myFunc(5);

  std::cout << giveMeNum() << '\n';
}

