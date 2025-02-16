#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  long n;
  std::cin >> n;

  std::vector<long> xs{std::istream_iterator<long>{std::cin},
                       std::istream_iterator<long>{}};
  std::ranges::sort(xs);

  auto median{xs.at(xs.size() / 2)};

  auto cost{0L};
  for (auto const &x : xs)
    cost += std::abs(x - median);
  std::cout << cost;

  return 0;
}
