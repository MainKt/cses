#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <span>
#include <vector>

long min_weight_diff(std::span<long> const selections, long total_weight,
                     std::vector<long> &subset) {
  if (selections.empty()) {
    auto subset_weight{std::reduce(subset.begin(), subset.end())};
    return std::abs(2 * subset_weight - total_weight);
  }

  long diff_without{min_weight_diff(
      selections.subspan(0, selections.size() - 1), total_weight, subset)};

  subset.push_back(selections.back());
  long diff_with{min_weight_diff(selections.subspan(0, selections.size() - 1),
                                 total_weight, subset)};
  subset.pop_back();

  return std::min(diff_without, diff_with);
}

long min_weight_diff(std::span<long> const selections) {
  auto total_weight{std::reduce(selections.begin(), selections.end())};
  std::vector<long> subset;
  return min_weight_diff(selections, total_weight, subset);
}

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::istream_iterator<long> istream(std::cin), istream_end;
  std::vector<long> apples{++istream, istream_end};
  std::ranges::sort(apples);

  std::cout << min_weight_diff(apples);

  return 0;
}
