#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
  long n{};
  std::cin >> n;

  std::vector<long> xs{std::istream_iterator<long>(std::cin),
                       std::istream_iterator<long>()};

  auto sum_till_n{(n * (n + 1) / 2)};
  std::cout << sum_till_n - std::reduce(xs.begin(), xs.end()) << '\n';

  return 0;
}
