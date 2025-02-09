#include <cmath>
#include <iostream>

long count_placements(long n) {
  auto const N_SQUARE{n * n};
  auto const TWO_ATTACK_POSITIONS{4 * (N_SQUARE - (2 + 1))},
      THREE_ATTACK_POSITIONS{8 * (N_SQUARE - (3 + 1))},
      FOUR_ATTACK_POSITIONS{4 * (n - 3) * (N_SQUARE - (4 + 1))},
      SIX_ATTACK_POSITIONS{4 * (n - 4) * (N_SQUARE - (6 + 1))},
      EIGHT_ATTACK_POSITIONS{(n - 4) * (n - 4) * (N_SQUARE - (8 + 1))};

  return (TWO_ATTACK_POSITIONS + THREE_ATTACK_POSITIONS +
          FOUR_ATTACK_POSITIONS + SIX_ATTACK_POSITIONS +
          EIGHT_ATTACK_POSITIONS) /
         2;
}

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long n;
  std::cin >> n;

  for (long i = 1; i <= n; i++) std::cout << count_placements(i) << '\n';

  return 0;
}
