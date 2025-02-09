#include <cmath>
#include <iostream>
#include <string>

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long q;
  std::cin >> q;

  while (q--) {
    long k;
    std::cin >> k;

    long length{1}, count{9}, start{1};

    while (k > length * count) {
      k -= length * count;
      length++;
      count *= 10;
      start *= 10;
    }

    auto number{start + (k - 1) / length};
    auto digit_index{(k - 1) % length};

    std::cout << std::to_string(number).at(digit_index) << '\n';
  }

  return 0;
}
