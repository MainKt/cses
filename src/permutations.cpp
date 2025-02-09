#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  long n = (std::cin >> n, n);
  std::vector<long> xs(n);

  if (n > 1 && n <= 3) {
    std::cout << "NO SOLUTION\n";
    return 0;
  }

  std::ranges::generate(xs, [i = 2, &n]() mutable {
    if (i > n) i = 1;
    return (i += 2) - 2;
  });
  std::ranges::copy(xs, std::ostream_iterator<long>{std::cout, " "});

  return 0;
}
