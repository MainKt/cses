#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <queue>
#include <vector>

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<long> xs(n);
  std::iota(xs.begin(), xs.end(), 1);

  auto sum{std::reduce(xs.begin(), xs.end())};

  if (sum % 2 == 0) {
    std::cout << "YES\n";
    auto target{sum / 2};
    std::deque<long> q;
    auto running_sum{0L};

    for (auto const &x : xs) {
      q.push_back(x);
      running_sum += x;

      while (running_sum > target) {
        running_sum -= q.front();
        q.pop_front();
      }

      if (running_sum == target) break;
    }

    std::cout << q.size() << '\n';
    std::ranges::copy(q, std::ostream_iterator<long>{std::cout, " "});
    std::cout << '\n';

    std::vector<long> remaining;
    std::set_difference(xs.begin(), xs.end(), q.begin(), q.end(),
                        std::back_inserter(remaining));
    std::cout << remaining.size() << '\n';
    std::ranges::copy(remaining, std::ostream_iterator<long>{std::cout, " "});
    std::cout << '\n';
  } else {
    std::cout << "NO\n";
  }

  return 0;
}
