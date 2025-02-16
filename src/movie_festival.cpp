#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

int main() {
  long n;
  std::cin >> n;

  std::vector<std::pair<long, long>> movies(n);
  for (auto &movie : movies)
    std::cin >> movie.first >> movie.second;
  std::ranges::sort(
      movies, [](auto const &a, auto const &b) { return a.second < b.second; });

  std::set<std::pair<long, long>> scheduled_movies;
  std::inclusive_scan(movies.begin(), movies.end(),
                      std::inserter(scheduled_movies, scheduled_movies.begin()),
                      [](auto const &last_movie, auto const &movie) {
                        return last_movie.second <= movie.first ? movie
                                                                : last_movie;
                      });
  std::cout << scheduled_movies.size();

  return 0;
}
