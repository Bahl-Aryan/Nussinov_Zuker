#include <catch2/catch_test_macros.hpp>
#include "nussinov.h"

/*
*Reads in the trivial_1.txt file and constructs the dynamic programming table for the string
*The table should be a 4x4 matrix, and the calculated score at a specfic index should match the expected 
*/

TEST_CASE("Correct DP Table") {
    std::vector<std::vector<int>> expected_table({
        {0, 1, 1, 2},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    });

    std::string rnaStrand = "data/trivial_1.txt";
    std::vector<std::vector<int>> res_table = createDPTable(rnaStrand);
    int expected_score = 1;
    int res_score = calculateScore(1, 2, rnaStrand, res_table);
    REQUIRE(expected_table == res_table);
    REQUIRE(res_score == expected_score);
}

/*
*Reads in the trivial_2.txt file and constructs the dynamic programming table for the string
*The table should be a 4x4 matrix, with the maximal score in the top right corner of the table
*Expected score of 3
*/

TEST_CASE("Correct DP Table 2") {
    std::vector<std::vector<int>> expected_table({
        {0, 0, 0, 0, 0 , 0, 1, 2, 3},
        {0, 0, 0, 0, 0 , 0, 1, 2, 3},
        {0, 0, 0, 0, 0 , 0, 1, 2, 2},
        {0, 0, 0, 0, 0 , 0, 1, 1, 1},
        {0, 0, 0, 0, 0 , 0, 1, 1, 1},
        {0, 0, 0, 0, 0 , 0, 1, 1, 1},
        {0, 0, 0, 0, 0 , 0, 0, 0, 0},
        {0, 0, 0, 0, 0 , 0, 0, 0, 0},
        {0, 0, 0, 0, 0 , 0, 0, 0, 0}
    });
    
    int expected_score = 3;
    std::string rnaStrand = "data/trivial_1.txt";
    std::vector<std::vector<int>> res_table = createDPTable(rnaStrand);
    int expected_score = 1;
    int res_score = calculateScore(1, 6, rnaStrand, res_table);
    
    REQUIRE(res_table[0, rnaStrand.length() - 1] == expected_score);
    REQUIRE(expected_table == res_table);
    REQUIRE(res_score == expected_score);
}

/*
*Reads in the trivial_1.txt file and produces solely the traceback from the correct table and strand
*Checks to see if the traceback function individually works
*/

TEST_CASE("Correct Traceback") {
    std::vector<std::vector<int>> expected_table(4, std::vector<int>(4));
    //TODO: initalize the expected table with the right values
    std::string rnaStrand = "data/trivial_1.txt";
    std::string expected_string = "(())";
    std::string res_string = traceback(0, 3, expected_table, rnaStrand);
    REQUIRE(res_string == expected_string);
}

/*
*Reads in the trivial_3.txt file and determines if the final produced string output matches the expected output
*/

TEST_CASE("Correct Nussinov") {
    std::string rnaStrand = "data/trivial_3.txt";
    std::string expected_string = "((((((....)))))(((((....)))))(((((....)))))(((((....)))))(((((....)))))";
    std::string res_string = nussinov(rnaStrand);
    REQUIRE(res_string == expected_string);
}