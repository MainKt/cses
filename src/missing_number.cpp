#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <vector>

int main() {
  long n{};
  std::cin >> n;

  std::set<long> xs{std::istream_iterator<long>(std::cin),
                    std::istream_iterator<long>()};

  std::vector<long> ys(n);
  std::iota(ys.begin(), ys.end(), 1);

  std::cout << *std::mismatch(xs.begin(), xs.end(), ys.begin()).second;

  return 0;
}
