#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
  std::size_t n;
  std::cin >> n;

  std::vector<std::pair<long, long>> xs;
  std::transform(std::istream_iterator<long>{std::cin},
                 std::istream_iterator<long>{}, std::back_inserter(xs),
                 [i = 1](auto const &x) mutable {
                   return std::pair{x, i++};
                 });
  std::ranges::sort(xs);

  std::vector<long> indices;
  std::ranges::transform(xs, std::back_inserter(indices),
                         [](auto const &x) { return x.second; });

  std::vector<bool> collections;
  std::adjacent_difference(indices.begin(), indices.end(),
                           std::back_inserter(collections),
                           [](auto const &a, auto const &b) { return a < b; });
  std::cout << std::ranges::count(collections, true);

  return 0;
}
