#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

#include <stdio.h>
#include <assert.h>
#include "hwexpressions.h"

// Test Case 1 Name: Test Get Sales Tax
void test_get_sales_tax() 
{
    // Create an assertion to verify that calling the get_sales_tax_amount function with parameter 10 returns the value .675
    assert(get_sales_tax_amount(10) == 0.675);

    // Create an assertion to verify that calling the get_sales_tax_amount function with parameter 20 returns the value 1.35
    assert(get_sales_tax_amount(20) == 1.35);
}

// Test Case 2 Name: Test Get Tip Amount
void test_get_tip_amount() 
{
    // Create an assertion to verify that calling the get_tip_amount function with parameters 20 and 15% returns the value 3
    assert(get_tip_amount(20, 0.15) == 3);

    // Create an assertion to verify that calling the get_tip_amount function with parameters 20 and 20% returns the value 4
    assert(get_tip_amount(20, 0.20) == 4);
}


