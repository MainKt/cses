#include <iostream>

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    // x + 2y = a => x = a - 2y
    // 2x + y = b => y = (2a - b) / 3
    long a, b;
    std::cin >> a >> b;
    auto y{(2 * a - b) / 3}, x{a - 2 * y};
    std::cout << ((x + 2 * y == a and 2 * x + y == b and x >= 0 and y >= 0)
                      ? "YES"
                      : "NO")
              << '\n';
  }

  return 0;
}
