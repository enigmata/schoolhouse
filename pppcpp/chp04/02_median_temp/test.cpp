#include "catch.hpp"
#include "median_temp.hpp"

std::vector<double> t0 = {};
std::vector<double> t1 = {23.5};
std::vector<double> t2 = {23.2,33.3};
std::vector<double> t3 = {33.3,23.2,44.4};

TEST_CASE("Simple test of basic variants", "[median]")
{
  //    The median of no temperatures is an error
  auto && [ m0, rc0 ] = median_temp(t0);
  REQUIRE(rc0 == return_code::err_no_temps);

  //    The median of a single temperature is that temperature
  auto && [ m1, rc1 ] = median_temp(t1);
  REQUIRE((rc1 == return_code::success && m1 == 23.5));

  //  The median of two temperatures is the average of those two temperatures
  auto && [ m2, rc2 ] = median_temp(t2);
  REQUIRE((rc2 == return_code::success && m2 == 28.25));

  //  The median of three temperatures is the middle (2nd) temperature
  auto && [ m3, rc3 ] = median_temp(t3);
  REQUIRE((rc3 == return_code::success && m3 == 33.3));
}
