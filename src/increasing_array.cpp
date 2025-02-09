#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
  std::istream_iterator<long> istream{std::cin}, istream_end{};

  long _ = *istream++;
  std::vector<long> xs{istream, istream_end};

  std::vector<long> ys;
  std::inclusive_scan(
      xs.begin(), xs.end(), std::back_inserter(ys),
      [](auto const &a, auto const &b) { return std::max(a, b); });

  std::cout << std::transform_reduce(ys.begin(), ys.end(), xs.begin(), 0L,
                                     std::plus{}, std::minus{});

  return 0;
}
