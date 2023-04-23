#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

#include "func.h"
#include "func.cpp"

// Define the test cases


TEST_CASE("get_gc_content returns correct value", "[get_gc_content]") {
    double result = get_gc_content("AGCTATAG");
    REQUIRE(result == 0.375);

    result = get_gc_content("CGCTATAG");
    REQUIRE(result == 0.5);
}

TEST_CASE("get_reverse_string returns correct value", "[get_reverse_string]") {
    std::string result = get_reverse_string("AGCTATAG");
    REQUIRE(result == "GATATCGA");

    result = get_reverse_string("CGCTATAG");
    REQUIRE(result == "GATATCGC");
}

TEST_CASE("get_dna_complement returns_correct_value", "[get_dna_complement]") {
    std::string result = get_dna_complement("AAAACCCGGT");
    REQUIRE(result == "ACCGGGTTTT");

    result = get_dna_complement("CCCGGAAAAT");
    REQUIRE_THAT(result, Catch::Matchers::Equals("ATTTTCCGGG"));
}

