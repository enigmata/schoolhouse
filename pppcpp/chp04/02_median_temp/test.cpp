#include "catch.hpp"
#include "median_temp.hpp"

std::vector<double> t0 = {};
std::vector<double> t1 = {23.5};
std::vector<double> t2 = {23.2,33.3};
std::vector<double> t3 = {33.3,23.2,44.4};

TEST_CASE("Simple test of basic variants", "[median]")
{
    REQUIRE(median_temp(t0)==0.0);
    REQUIRE(median_temp(t1)==23.5);
    REQUIRE(median_temp(t2)==28.25);
    REQUIRE(median_temp(t3)==33.3);
}
