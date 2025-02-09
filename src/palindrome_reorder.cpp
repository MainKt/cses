#include <algorithm>
#include <iostream>
#include <unordered_map>

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;

  std::unordered_map<char, long> frequency;
  for (auto const &c : s) frequency[c]++;

  auto odds{std::ranges::count_if(
      frequency, [](auto const &kv) { return kv.second % 2 != 0; })};

  if (odds != 1 and odds != 0) {
    std::cout << "NO SOLUTION\n";
  } else {
    std::string left, mid;
    for (auto const &[c, count] : frequency) {
      if (count % 2 == 0) {
        left.append(count / 2, c);
      } else {
        mid.append(count, c);
      }
    }
    std::string right{left.rbegin(), left.rend()};
    std::cout << left + mid + right << '\n';
  }

  return 0;
}
