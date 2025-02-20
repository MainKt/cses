#include <iostream>
#include <iterator>
#include <set>

int main() {
  long x, n;
  std::cin >> x >> n;

  std::set<long> points{0, x};
  std::multiset<long> lengths{x - 0};

  for (auto i{0}; i < n; i++) {
    long p;
    std::cin >> p;

    auto [it, _]{points.insert(p)};
    auto prev{*std::prev(it)}, next{*std::next(it)};

    lengths.erase(lengths.find(next - prev));
    lengths.insert(p - prev), lengths.insert(next - p);

    std::cout << *lengths.rbegin() << '\n';
  }

  return 0;
}
