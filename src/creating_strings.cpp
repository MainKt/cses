#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

std::set<std::string> generate_permutations(std::multiset<char> choices,
                                            std::string permutation = "") {
  if (choices.empty()) return {permutation};
  std::set<std::string> permutations;
  for (auto const &choice : choices) {
    auto new_choices{choices};
    new_choices.erase(new_choices.find(choice));
    permutations.merge(
        generate_permutations(new_choices, permutation + choice));
  }
  return permutations;
}

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;
  // std::ranges::sort(s);

  // std::vector<std::string> permutations;
  // do permutations.push_back(s);
  // while (std::ranges::next_permutation(s).found);

  auto permutations{generate_permutations({s.begin(), s.end()})};
  std::cout << permutations.size() << '\n';
  std::ranges::copy(permutations,
                    std::ostream_iterator<std::string>{std::cout, "\n"});

  return 0;
}
