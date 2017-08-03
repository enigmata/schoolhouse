#include "city_dist.hpp"

#include <limits>
#include <tuple>
#include <vector>

/* Compute various distance metrics given a sequence of distances between cities
 * along a route
 *
 * Input:
 *   - vector of distances between two cities along a given route
 * Output:
 *   1) total distance of the entire route
 *   2) smallest distance between two neighbouring cities
 *   3) greatest distance between two neighbouring cities
 *   4) mean distance between two neighbouring cities
 *   5) return code indicating success or failure of the computation
 */
return_type city_distances(const std::vector<double> &dists) {

  return_code rc{return_code::success};
  double total_dist{0.0}, mean_dist{0.0};
  double shortest_dist{std::numeric_limits<double>::max()};
  double longest_dist{std::numeric_limits<double>::min()};

  if (!dists.empty()) {

    for (double d : dists) {
      if (d <= 0.0) {
        rc = return_code::err_negative_or_zero_distance;
        break;
      }

      total_dist += d;
      if (d > longest_dist)
        longest_dist = d;
      if (d < shortest_dist)
        shortest_dist = d;
    }

    if (rc == return_code::success)
      mean_dist = total_dist / dists.size();

  } else {
    rc = return_code::err_no_distances;
  }

  return {total_dist, shortest_dist, longest_dist, mean_dist, rc};
}
