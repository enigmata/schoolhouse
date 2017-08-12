#include "catch.hpp"
#include "city_dist.hpp"

// conventions:
//    id9 == input data set # 9
//    od9 == (expected) output data set # 9
//    rd9 == (actual) result data set # 9
//    t9  == total distance for data set # 9
//    s9  == shortest distance for data set # 9
//    g9  == greatest distance for data set # 9
//    m9  == mean distance for data set # 9
//    rc9 == return code for data set # 9

TEST_CASE("Simple test of basic but correct variants", "[distances_good]") {
  // variant 1:
  //   single distance for a route with only one pair of cities
  //       city 1 <-- 23.5 km --> city 2
  //   yields distance metrics all the same:
  //     total == longest == shortest == mean
  std::vector<double> id1 = {23.5};
  return_type od1 = {23.5, 23.5, 23.5, 23.5, return_code::success};

  auto &&rd1 = city_distances(id1);
  REQUIRE(rd1 == od1);

  // variant 2:
  //   three cities, two pair-wise distances
  //     city 1 <-- 23.2 km --> city 2 <-- 33.3 km --> city 3
  std::vector<double> id2 = {23.2, 33.3};
  return_type od2 = {56.5, 23.2, 33.3, 28.25, return_code::success};

  auto &&rd2 = city_distances(id2);
  REQUIRE(rd2 == od2);

  // variant 3:
  //   four cities, three pair-wise distances
  //     city 1 <- 33.3 km -> city 2 <- 23.2 km -> city 3 <- 44.4 km -> city 4
  std::vector<double> id3 = {33.3, 23.2, 44.4};
  return_type od3 = {100.9, 23.2, 44.4, 100.9 / 3, return_code::success};

  auto &&rd3 = city_distances(id3);
  REQUIRE(rd3 == od3);
}

TEST_CASE("Test of basic incorrect variants", "[distances_bad]") {
  // variant 1:
  //   no distances is an error
  std::vector<double> id10 = {};

  auto && [ t10, s10, g10, m10, rc10 ] = city_distances(id10);
  REQUIRE(rc10 == return_code::err_no_distances);

  // variant 2:
  //   0.0 distances do not make sense
  std::vector<double> id11 = {3.56, 0.0, 1.23};

  auto && [ t11, s11, g11, m11, rc11 ] = city_distances(id11);
  REQUIRE(rc11 == return_code::err_negative_or_zero_distance);

  // variant 3:
  //   negative distances do not make sense
  std::vector<double> id12 = {10003.56, 0.04, -201.83};

  auto && [ t12, s12, g12, m12, rc12 ] = city_distances(id12);
  REQUIRE(rc12 == return_code::err_negative_or_zero_distance);
}
