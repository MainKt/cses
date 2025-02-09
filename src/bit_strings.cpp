#include <cmath>
#include <cstdint>
#include <iostream>

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::uint64_t n;
  std::cin >> n;

  std::uint64_t const MOD = 1000000007;

  std::uint64_t value{1};
  while (n--) value = (value * 2) % MOD;
  std::cout << value << '\n';

  return 0;
}
