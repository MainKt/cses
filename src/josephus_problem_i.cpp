#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

int main() {
  long n;
  std::cin >> n;

  std::set<long> set;
  std::generate_n(std::inserter(set, set.begin()), n,
                  [i = 1]() mutable { return i++; });

  auto circular_upper_bound{
      [&set](auto const &it) {
        auto ub{set.upper_bound(*it)};
        return ub != set.end() ? ub : set.begin();
      },
  };

  for (auto it{circular_upper_bound(set.begin())}; not set.empty();
       it = circular_upper_bound(it)) {
    std::cout << *it << ' ';
    auto next{std::next(it)};
    set.erase(it);
    it = next != set.end() ? next : set.begin();
  }

  return 0;
}
