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
  std::ranges::sort(xs);

  std::vector<long> scan{0};
  std::inclusive_scan(xs.begin(), xs.end(), std::back_inserter(scan));
  std::ranges::transform(scan, scan.begin(),
                         [](auto const &x) { return x + 1; });

  auto missing_coin{
      *std::ranges::mismatch(xs, scan, [](auto const &x, auto const &s) {
         return x <= s;
       }).in2};
  std::cout << missing_coin;

  return 0;
}
