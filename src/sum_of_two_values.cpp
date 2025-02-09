#include <iostream>
#include <iterator>
#include <map>

int main() {
  long n, target_sum;
  std::cin >> n >> target_sum;

  std::multimap<long, long> x_to_i;
  for (auto i{1L}; i <= n; i++) {
    long x;
    std::cin >> x;
    x_to_i.emplace(x, i);
  }

  for (auto const &[x, i] : x_to_i) {
    auto y{target_sum - x};
    if (auto it{x_to_i.find(y)}; it != x_to_i.end()) {
      if (it->second == i) it = std::next(it);
      if (it != x_to_i.end() and it->first == y) {
        std::cout << i << " " << it->second << '\n';
        return 0;
      }
    }
  }

  std::cout << "IMPOSSIBLE\n";

  return 0;
}
