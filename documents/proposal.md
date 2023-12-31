## Academic Reference
The algorithm that is being implemented is Nussinov's Algorithm for predicting RNA secondary structure, as seen in the following publications: (https://epubs.siam.org/doi/10.1137/0135006) and (https://www.ncbi.nlm.nih.gov/pmc/articles/PMC350273/). 

To assist with understanding and writing the algorithm, the wikipedia page for Nussinov's algorithm provides the necessary pseudocode (https://en.wikipedia.org/wiki/Nussinov_algorithm)

## Algorithm Summary
When implemented properly, Nussinov's algorithm helps provide a basic prediction for RNA secondary structure using dynamic programming and backtracing. The dynamic table is filled out finding the maximum scores between two indices (RNA nucleotides), and the backtrace is determined by recursing through the dynamic table and appending indices to a list. This list can then be read to produce a secondary structure prediction in the format of "*" and "(".

## Function I/O
As mentioned in the summary, there are two main steps to this program: filling out the dynamic table and reading/writing the backtrace. However, it would be beneficial to create some helper methods to make the code more readable.

1. `int calculateScore(int A, int B, std::string rnaStrand, std::vector<std::vector<int>> & dpTable)`
```
@param A/B -- index of nucleotides in the RNA sequence that will be checked to see if they are complimentary
@param rnaStrand -- this is the string representation of the RNA sequence to be analyzed
@param dpTable -- this is the dynamic programming table that will hold all the maximum scores at given indices
@return -- an int describing the max score between these indices
```
This helper function will determine the maximum score at two indices by taking in two "int" params for the indices, the RNA sequence to be analyzed, and the dynamic programming table that will be filled in. The maximum score is returned by finding the maximum score between all the possible subsequences between the given indices through the dynamic table. Our proposed tests (1 and 2) check to see if this function correctly determines the calculated score at a given index with two different RNA strand inputs. Test 1 checks this condition on the pre-determined table, while Test 2 tests this function on the resulting table. Together, if the function passes, we can be sure the function is implemented correctly.

2. `std::vector<std::vector<int>> createDPTable(std::string rnaStrand)`
```
@param rnaStrand -- the string representation of the RNA sequence to be analyzed
@return -- a table created as a std::vector<std::vector<int>> that logs all the maximum scores
```
This is the main dynamic programming function that calls the helper "calculateScore" method at every pair of indices. Storing the maximum scores allows for easy access to previously calculated scores, instead of having to recalculate them every iteration. This function will first initialize the entire NxN "matrix" (where N is the length of the passed rnaStrand) with 0s, and will then fill the matrix in a diagonal manner. The first two test cases implemented check to see if the "createDPTable" is correctly implemented by checking to see if the final score is as expected, along with the comparing the created DP Table. The tables are created through various RNA strand lengths, so passing both cases indicates that the table contains the right maximum score while also being populated correctly.

3. `std::string traceback(int i, int j, std::vector<std::vector<int>> dpTable, std::string rnaStrand)`
```
@param i/j -- designate the starting indices for the Nussinov algorithm (typically the first and last character of the RNA sequence)
@param dpTable -- the completed dynamic programming table created through the "createDPTable" function that stores all the maximum scores
@param rnaStrand -- the RNA sequence to be analyzed for secondary structure
@return -- an std::string representing the secondary structure using "*" and "()"
```
This function is called recursively to determine the traceback of the maximum calculated score of the dynamic programming table, located at the top right corner. The returned string is the most commonly used format of the Nussinov algorithm, which uses "()" to designate which nucleotides are bound to each other. Our proposed test cases (3 and 4) check this functions implementation through both a pre-determined table and through the full algorithm (assuming the previous test cases for correctly implemented tables pass). By passing both test cases, we demonstrate the algorithms correctness on various table sizes and sequences.

4. `std::string nussinov(std::string rnaStrand)`
```
@param rnaStrand -- the RNA sequence to be pushed through the cumulative algorithm
@return -- std::string representing the secondary structure
```
This is the cumulative function of the creating the dynamic table and running the traceback, returning the string generated from the traceback function. Our proposed test 4 is used to check if all the moving parts, from calculating an individual index score to generating the backtrace, mesh properly. By passing this test case, we show that the overall algorithm is correctly implemented, including the transitions between helper methods.

*May implement class 'Nussinov' to avoid unneccessary repetition of variables, depending on readability and efficiency of code*

**Will continue to write more test cases to ensure that all possible edge cases are taken care of!**

## Data Description
Test datasets were manually constructed to guarantee that expected output for each test case was correct. The actual datasets stored in `/data` consist of arbitrary RNA strands represented as strings of the letter(s) AUCG that we will perform the Nussinov algorithm on. Potential datasets would involve actual RNA strands pulled from reputable sources through simple-copy pasting. 
