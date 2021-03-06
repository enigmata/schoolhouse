#include <algorithm>
#include <vector>

#include "median_temp.hpp"

std::pair<double, return_code> median_temp(std::vector<double> &temps) {
  double median = 0.0;
  return_code rc = return_code::success;

  if (!temps.empty()) {
    std::sort(temps.begin(), temps.end());

    if (temps.size() % 2 == 0) {
      // The median of an even number of temperatures is the
      // mean of middle two temperatures in the sequence.
      int middle_left = (temps.size() / 2) - 1, middle_right = middle_left + 1;
      median = (temps[middle_left] + temps[middle_right]) / 2.0;
    } else {
      median = temps[temps.size() / 2]; // depend on rounding down
    }
  } else {
    rc = return_code::err_no_temps;
  }

  return {median, rc};
}
