#include "multiples_of.hpp"
#include <cmath>

long int series_max(long int n, long int ceiling);
long long int power_sum(long int n);
return_code validate(int x, int y, long int ceiling);

// Given natural numbers x and y, compute the sum of all multiples
// of x and y below the ceiling
//  e.g. given x=3, y=5, ceiling=10, the sum is 3+5+6+9=23.
//
// Method A: Brute force.
return_type multiples_of_x_and_y_brute(int x, int y, long int ceiling) {
  long long int sum{0};
  return_code rc{return_code::success};

  rc = validate(x, y, ceiling);
  if (rc == return_code::success) {
    for (long int i = 1; i < ceiling; i++)
      if (i % x == 0 || i % y == 0)
        sum += i;
  }

  return {sum, rc};
}
//
// Method B: Power Sums
//
// Sum each natural number, x and y, individually using the power
// sum closed form, and subtract out the power sum of the product
// of x and y so as not to double count.
//
// Power Sum:  (n*(n+1))/2
//
// Example:  x=3, y=5, ceiling=100
//        x: 3+6+9+12+15+...+99 = 3*(1+2+3...+33) = 3*(33*(33+1))/2 = 1683
//        y: 5+10+15+...+95 = 5*(1+2+3...+19) = 5*(19*(19+1))/2 = 950
//      x*y: 15+30+...+90 = 15*(1+2+3+4+5+6) = 15*(6*(6+1))/2 = 315
//   answer: 1683 + 950 - 315 = 2318
return_type multiples_of_x_and_y_psum(int x, int y, long int ceiling) {
  return_code rc{return_code::success};
  long long int sum{0};

  rc = validate(x, y, ceiling);
  if (rc == return_code::success) {
    sum = x * power_sum(series_max(x, ceiling)) +
          y * power_sum(series_max(y, ceiling));
    if (long int xy = x * y; xy < ceiling) {
      sum -= xy * power_sum(series_max(xy, ceiling));
    }
  }
  return {sum, rc};
}

inline long int series_max(long int n, long int ceiling) {
  return (long int)std::floor((double)(ceiling - 1) / (double)n);
}

inline long long int power_sum(long int n) { return (n * (n + 1)) / 2; }

return_code validate(int x, int y, long int ceiling) {
  return_code rc{return_code::success};

  if (x < 1 || y < 1 || ceiling < 1) {
    rc = return_code::err_not_natural_nums;
  } else if (ceiling <= x || ceiling <= y) {
    rc = return_code::err_ceiling_too_low;
  } else if (x == y) {
    rc = return_code::err_x_equals_y;
  }
  return rc;
}
