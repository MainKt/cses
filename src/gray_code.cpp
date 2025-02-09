#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<std::string> generate_gray_code(long n) {
  if (n == 1) return {"0", "1"};

  std::vector<std::string> prev_code{generate_gray_code(n - 1)},
      reversed_code{prev_code.rbegin(), prev_code.rend()};

  std::ranges::transform(prev_code, prev_code.begin(),
                         [](auto const &code) { return "0" + code; });
  std::ranges::transform(reversed_code, reversed_code.begin(),
                         [](auto const &code) { return "1" + code; });

  std::vector<std::string> gray_code;
  std::ranges::copy(prev_code, std::back_inserter(gray_code));
  std::ranges::copy(reversed_code, std::back_inserter(gray_code));

  return gray_code;
}

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::size_t n;
  std::cin >> n;

  std::ranges::copy(generate_gray_code(n),
                    std::ostream_iterator<std::string>{std::cout, "\n"});

  return 0;
}
