#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  long n{};
  std::cin >> n;

  std::vector<long> series{n};
  while (n != 1) series.push_back(n = n % 2 == 0 ? n / 2 : n * 3 + 1);
  std::copy(series.begin(), series.end(),
            std::ostream_iterator<long>{std::cout, " "});

  return 0;
}
