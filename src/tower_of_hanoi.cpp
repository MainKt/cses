#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<std::pair<short, short>> solve_tower_of_hanoi(int n,
                                                          short source = 1,
                                                          short aux = 2,
                                                          short dest = 3) {
  if (n == 0) return {};
  std::vector<std::pair<short, short>> moves;

  auto source2aux{solve_tower_of_hanoi(n - 1, source, dest, aux)};
  std::ranges::copy(source2aux, std::back_inserter(moves));

  moves.emplace_back(source, dest);

  auto aux2dest{solve_tower_of_hanoi(n - 1, aux, source, dest)};
  std::ranges::copy(aux2dest, std::back_inserter(moves));

  return moves;
}

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::size_t n;
  std::cin >> n;

  auto moves{solve_tower_of_hanoi(n)};
  std::cout << moves.size() << '\n';
  for (auto const &[source, dest] : moves)
    std::cout << source << ' ' << dest << '\n';

  return 0;
}
