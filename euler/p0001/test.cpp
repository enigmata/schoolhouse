#include "catch.hpp"
#include "multiples_of.hpp"

///////////////////////////////////////////////////////
// Test cases exercising the power sum algorithm
///////////////////////////////////////////////////////

//
// Error test cases
//

TEST_CASE("power sum: x is not a natural number", "[input_bad],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(0, 1, 2);
  REQUIRE(rc == return_code::err_not_natural_nums);
}

TEST_CASE("power sum: y is not a natural number", "[input_bad],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(1, -1, 2);
  REQUIRE(rc == return_code::err_not_natural_nums);
}

TEST_CASE("power sum: ceiling isn't a natural num", "[input_bad],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(1, 3, -2);
  REQUIRE(rc == return_code::err_not_natural_nums);
}

TEST_CASE("power sum: ceiling too low", "[input_bad],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(3, 5, 5);
  REQUIRE(rc == return_code::err_ceiling_too_low);
}

TEST_CASE("power sum: x cannot equal y", "[input_bad],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(3, 3, 10);
  REQUIRE(rc == return_code::err_x_equals_y);
}

//
// Correct answer test cases
//

TEST_CASE("power sum: don't subtract x*y multiples",
          "[partial_code],[correct],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(2, 3, 6);
  REQUIRE(sum == 9);
}

TEST_CASE("power sum: x=3, y=5, ceiling=10", "[correct],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(3, 5, 10);
  REQUIRE(sum == 23);
}

TEST_CASE("power sum: x=3, y=5, ceiling=100", "[correct],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(3, 5, 100);
  REQUIRE(sum == 2318);
}

TEST_CASE("power sum: x=3, y=5, ceiling=1000", "[correct],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(3, 5, 1000);
  REQUIRE(sum == 233168);
}

TEST_CASE("power sum: x=9, y=2, ceiling=1000", "[correct],[power_sum]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_psum(9, 2, 1000);
  REQUIRE(sum == 277724);
}

///////////////////////////////////////////////////////
// Test cases exercising the brute force algorithm
///////////////////////////////////////////////////////

//
// Error test cases
//

TEST_CASE("brute force: x is not a natural number",
          "[input_bad],[brute_force]") {
  auto && [ s1, rc1 ] = multiples_of_x_and_y_brute(0, 1, 2);
  REQUIRE(rc1 == return_code::err_not_natural_nums);
}

TEST_CASE("brute force: y is not a natural number",
          "[input_bad],[brute_force]") {
  auto && [ s2, rc2 ] = multiples_of_x_and_y_brute(1, -1, 2);
  REQUIRE(rc2 == return_code::err_not_natural_nums);
}

TEST_CASE("brute force: ceiling isn't a natural num",
          "[input_bad],[brute_force]") {
  auto && [ s3, rc3 ] = multiples_of_x_and_y_brute(1, 3, -2);
  REQUIRE(rc3 == return_code::err_not_natural_nums);
}

TEST_CASE("brute force: ceiling too low", "[input_bad],[brute_force]") {
  auto && [ s4, rc4 ] = multiples_of_x_and_y_brute(3, 5, 5);
  REQUIRE(rc4 == return_code::err_ceiling_too_low);
}

TEST_CASE("brute force: x cannot equal y", "[input_bad],[brute_force]") {
  auto && [ s7, rc7 ] = multiples_of_x_and_y_brute(3, 3, 10);
  REQUIRE(rc7 == return_code::err_x_equals_y);
}

//
// Correct answer test cases
//

TEST_CASE("brute force: don't subtract x*y multiples",
          "[partial_code],[correct],[brute_force]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_brute(2, 3, 6);
  REQUIRE(sum == 9);
}

TEST_CASE("brute force: x=3, y=5, ceiling=10", "[correct],[brute_force]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_brute(3, 5, 10);
  REQUIRE(sum == 23);
}

TEST_CASE("brute force: x=3, y=5, ceiling=100", "[correct],[brute_force]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_brute(3, 5, 100);
  REQUIRE(sum == 2318);
}

TEST_CASE("brute force: x=3, y=5, ceiling=1000", "[correct],[brute_force]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_brute(3, 5, 1000);
  REQUIRE(sum == 233168);
}

TEST_CASE("brute force: x=9, y=2, ceiling=1000", "[correct],[brute_force]") {
  auto && [ sum, rc ] = multiples_of_x_and_y_brute(9, 2, 1000);
  REQUIRE(sum == 277724);
}
