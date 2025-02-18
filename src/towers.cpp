#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
  long n;
  std::cin >> n;

  std::vector<long> xs{
      std::istream_iterator<long>{std::cin},
      std::istream_iterator<long>{},
  };

  std::multiset<long> set;
  for (auto const &x : xs) {
    if (auto bottom{set.upper_bound(x)}; bottom != set.end())
      set.erase(bottom);
    set.insert(x);
  }
  std::cout << set.size();

  return 0;
}
