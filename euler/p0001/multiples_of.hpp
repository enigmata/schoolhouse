#ifndef __MULTIPLES_OF_HPP__
#define __MULTIPLES_OF_HPP__

#include <tuple>

enum class return_code {
  success,
  err_not_natural_nums,
  err_ceiling_too_low,
  err_x_equals_y
};

using return_type = std::tuple<long long int, return_code>;

// Given natural numbers x and y, compute the sum of all multiples
// of x and y below the ceiling
//  e.g. given x=3, y=5, ceiling=10, the sum is 3+5+6+9=23.
//
//  Method A: Brute Force
return_type multiples_of_x_and_y_brute(int x, int y, long int ceiling);
//  Method B: Power Sums
return_type multiples_of_x_and_y_psum(int x, int y, long int ceiling);

#endif // __MULTIPLES_OF_HPP__
