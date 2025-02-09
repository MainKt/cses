#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    long x, y;
    std::cin >> x >> y;

    auto max{std::max(x, y)};
    auto middle_value{max * (max - 1) + 1};
    auto answer{middle_value + (x - y) * (max % 2 == 0 ? 1 : -1)};
    std::cout << answer << '\n';
  }
}
