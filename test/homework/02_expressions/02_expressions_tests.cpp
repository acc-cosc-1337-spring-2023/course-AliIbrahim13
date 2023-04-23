#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"


// Test Case 1: get_sales_tax_amount function
TEST_CASE("get_sales_tax_amount", "[get_sales_tax_amount]") {
    REQUIRE(get_sales_tax_amount(10) == 0.675);
    REQUIRE(get_sales_tax_amount(20) == 1.35);
}

// Test Case 2: get_tip_amount function
TEST_CASE("get_tip_amount", "[get_tip_amount]") {
    REQUIRE(get_tip_amount(20, 0.15) == 3);
    REQUIRE(get_tip_amount(20, 0.2) == 4);
}
