#include <cmath>
#include <iostream>

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long n;
  std::cin >> n;

  auto zeros{0};
  while (n > 0) zeros += n /= 5;
  std::cout << zeros << '\n';

  return 0;
}
