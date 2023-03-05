#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

#include "decisions.h"
#include "gtest/gtest.h"

// Test get_letter_grade_using_if function
TEST(GetLetterGradeUsingIfTest, HandlesValidInput) {
    REQUIRE(get_letter_grade_using_if(95), "A");
    REQUIRE(get_letter_grade_using_if(85), "B");
    REQUIRE(get_letter_grade_using_if(75), "C");
    REQUIRE(get_letter_grade_using_if(65), "D");
    REQUIRE(get_letter_grade_using_if(50), "F");
}

TEST(GetLetterGradeUsingIfTest, HandlesInvalidInput) {
    REQUIRE(get_letter_grade_using_if(-5), "Out of range");
    REQUIRE(get_letter_grade_using_if(105), "Out of range");
}

// Test get_letter_grade_using_switch function
TEST(GetLetterGradeUsingSwitchTest, HandlesValidInput) 
{
    REQUIRE(get_letter_grade_using_switch(95), "A");
    REQUIRE(get_letter_grade_using_switch(85), "B");
    REQUIRE(get_letter_grade_using_switch(75), "C");
    REQUIRE(get_letter_grade_using_switch(65), "D");
    REQUIRE(get_letter_grade_using_switch(50), "F");
}

TEST(GetLetterGradeUsingSwitchTest, HandlesInvalidInput)
{
    REQUIRE(get_letter_grade_using_switch(-5), "Out of range");
    REQUIRE(get_letter_grade_using_switch(105), "Out of range");
}
