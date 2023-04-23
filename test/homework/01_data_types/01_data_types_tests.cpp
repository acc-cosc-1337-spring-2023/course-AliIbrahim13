#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "data_types.h"
#include "catch.hpp"
#include "data_types.h"

TEST_CASE("Test Multiply Numbers")
{
  REQUIRE(multiply_numbers(10) == 50);
  REQUIRE(multiply_numbers(2) == 10);
}
