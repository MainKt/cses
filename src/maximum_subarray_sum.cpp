#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
  long n;
  std::cin >> n;

  std::vector<long> xs{std::istream_iterator<long>{std::cin},
                       std::istream_iterator<long>{}};

  std::vector<long> scan;
  std::inclusive_scan(
      xs.begin(), xs.end(), std::back_inserter(scan),
      [](auto const &acc, auto const &x) { return std::max(acc + x, x); });

  std::cout << *std::ranges::max_element(scan);

  return 0;
}
