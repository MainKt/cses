#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  ulong n, m;
  std::cin >> n >> m;

  std::vector<ulong> xs(n);
  for (auto &x : xs) std::cin >> x;
  std::ranges::transform(xs, xs.begin(), [](auto const &x) { return x - 1; });

  std::vector<ulong> indices(n);
  for (auto i{0UL}; i < n; i++) indices.at(xs.at(i)) = i;

  std::set<std::pair<ulong, ulong>> inversions;
  for (auto i{0UL}, j{1UL}; j < indices.size(); i++, j++) {
    if (indices.at(i) > indices.at(j)) inversions.emplace(i, j);
  }

  auto remove_inversions{
      [&inversions, &indices](auto const &x) {
        if (x != 0) inversions.erase({x - 1, x});
        if (x != indices.size() - 1) inversions.erase({x, x + 1});
      },
  };
  auto add_inversions{
      [&inversions, &indices](auto const &x) {
        if (x != 0 and indices.at(x - 1) > indices.at(x))
          inversions.insert({x - 1, x});
        if (x != indices.size() - 1 and indices.at(x) > indices.at(x + 1))
          inversions.insert({x, x + 1});
      },
  };

  while (m--) {
    ulong i, j;
    std::cin >> i >> j;
    i--, j--;

    auto &xi{xs.at(i)}, &xj{xs.at(j)};
    remove_inversions(xi), remove_inversions(xj);

    std::swap(xi, xj);
    std::swap(indices.at(xi), indices.at(xj));
    add_inversions(xi), add_inversions(xj);

    std::cout << inversions.size() + 1 << '\n';
  }

  return 0;
}
