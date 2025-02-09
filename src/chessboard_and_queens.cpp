#include <iostream>
#include <vector>

bool is_vertically_safe(std::vector<std::vector<char>> const &board,
                        std::size_t row, std::size_t column) {
  for (std::size_t i{0}; i < row; i++) {
    if (board.at(i).at(column) == 'Q') return false;
  }
  return true;
}

bool is_diagonally_safe(std::vector<std::vector<char>> const &board, long row,
                        long column) {
  for (long i{(row - 1)}, j{(column - 1)}; i >= 0 and j >= 0; i--, j--) {
    if (board.at(i).at(j) == 'Q') return false;
  }

  long size = board.size();
  for (long i{(row - 1)}, j{(column + 1)}; i >= 0 and j < size; i--, j++) {
    if (board.at(i).at(j) == 'Q') return false;
  }

  return true;
}

std::size_t count_queen_placements(std::vector<std::vector<char>> &board,
                                   std::size_t row = 0) {
  if (row == board.size()) return 1;

  std::size_t count{0};
  for (std::size_t column{0}; column < board.size(); column++) {
    auto &cell = board.at(row).at(column);
    if (cell == '*') continue;
    if (not is_vertically_safe(board, row, column)) continue;
    if (not is_diagonally_safe(board, row, column)) continue;

    cell = 'Q';
    count += count_queen_placements(board, row + 1);
    cell = '.';
  }
  return count;
}

int main() {
  std::iostream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  auto const n{8};
  std::vector<std::vector<char>> board(n, std::vector<char>(8));

  for (auto &row : board) {
    for (auto &cell : row) std::cin >> cell;
  }
  std::cout << count_queen_placements(board) << '\n';

  return 0;
}
