#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;

  std::vector<long> diffs;
  std::adjacent_difference(s.begin(), s.end(), std::back_inserter(diffs),
                           [equals = 0](auto const &a, auto const &b) mutable {
                             return equals = a == b ? equals + 1 : 0;
                           });
  std::cout << *std::max_element(diffs.begin() + 1, diffs.end()) + 1 << '\n';

  return 0;
}
