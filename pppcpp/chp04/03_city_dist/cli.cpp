#include <iostream>
#include <vector>

#include "city_dist.hpp"

int main()
{
  std::cout
      << "\nExercise: Given a sequence of distances, the distances\n"
      << "between neighbouring houses along a route, compute the\n"
      << "following metrics:\n"
      << "\tTotal distance of the entire route\n"
      << "\tSmallest distance between any two cities along the route\n"
      << "\tGreatest distance between any two cities along the route\n"
      << "\tMean distance between two neighbouring cities\n\n"
      << "Enter one or more distances, then enter Ctrl-D to see the results:\n";

  std::vector<double> dists;

  for (double dist; std::cin >> dist;)
    dists.push_back(dist);

  auto && [ total, smallest, greatest, mean, rc ] = city_distances(dists);

  switch (rc) {
  case return_code::success:
    std::cout << "Total:    " << total << "\n"
              << "Smallest: " << smallest << "\n"
              << "Greatest: " << greatest << "\n"
              << "Mean:     " << mean << "\n\n";
    break;

  case return_code::err_no_distances:
    std::cout << "Error: At least one distance is required!\n";
    break;

  case return_code::err_negative_or_zero_distance:
    std::cout << "Error: Negative or zero distance values are not allowed!\n";
    break;

  default:
    std::cout << "Error: Unknown!\n";
  }

  return static_cast<int>(rc);
}
