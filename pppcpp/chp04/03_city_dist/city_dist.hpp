#include <tuple>
#include <vector>

#ifndef __CITY_DISTANCES_HPP__
#define __CITY_DISTANCES_HPP__

enum class return_code {
  success,
  err_no_distances,
  err_negative_or_zero_distance
};

/*
 * return_type tuple content:
 *   1) double      - total distance of the entire route
 *   2) double      - smallest distance between two neighbouring cities
 *   3) double      - greatest distance between two neighbouring cities
 *   4) double      - mean distance between two neighbouring cities
 *   5) return_code - indicates success or failure of the computation
 */
using return_type = std::tuple<double, double, double, double, return_code>;

/* Compute various distance metrics (return_type) given a sequence of distances
 * between cities along a supplied route
 */
return_type city_distances(const std::vector<double> &dists);

#endif // __CITY_DISTANCES_HPP__
