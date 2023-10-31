#include <catch2/catch_test_macros.hpp>
#include "nussinov.h"

/*
*Reads in the trivial_1.txt file and constructs the dynamic programming table for the string
*The table should be a 4x4 matrix 
*/

TEST_CASE("Correct DP Table") {
    std::vector<std::vector<int>> expected_table(4, std::vector<int>(4));
    //initalize the expected table with the right values
    std::string rnaStrand = "data/trivial_1.txt"
    std::vector<std::vector<int>> res_table = createDPTable(rnaStrand);
    REQUIRE(expected_table == res_table);
}