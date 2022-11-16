#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main() {
  std::ifstream f{"words.txt"};
  std::map<std::string, int> words{};

  std::string word{};
  while (std::getline(f, word)) {
    ++words[word];
  }

  for (auto & [word, count] : words) {
    std::cout << word << ' ' << count << '\n';
  }
}
