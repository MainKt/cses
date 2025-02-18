#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

int main() {
  long n;
  std::cin >> n;

  std::vector<long> xs{std::istream_iterator<long>{std::cin},
                       std::istream_iterator<long>{}};

  std::map<long, long> x_to_i;
  auto running_length{0L}, longest_length{0L}, start_index{0L};

  for (auto i{0L}; i < n; i++) {
    auto x{xs.at(i)};

    if (x_to_i.contains(x) and start_index <= x_to_i[x]) {
      start_index = x_to_i[x] + 1;
      running_length = i - x_to_i[x];
    } else {
      running_length++;
    }

    x_to_i[x] = i;

    longest_length = std::max(longest_length, running_length);
  }

  std::cout << longest_length;

  return 0;
}
