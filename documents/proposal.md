## Academic Reference
The algorithm that we are proposing to implement is Nussinov's Algorithm for predicting RNA secondary structure, as seen in the following publications: (https://epubs.siam.org/doi/10.1137/0135006) and (https://www.ncbi.nlm.nih.gov/pmc/articles/PMC350273/). 

To assist with understanding and writing the algorithm, the wikipedia page for Nussinov's algorithm provides the necessary pseudocode (https://en.wikipedia.org/wiki/Nussinov_algorithm)

## Algorithm Summary
When implemented properly, Nussinov's algorithm helps provide a basic prediction for RNA secondary structure using dynamic programming and backtracing. The dynamic table is filled out finding the maximum scores between two indices (RNA nucleotides), and the backtrace is determined by recursing through the dynamic table and appending indices to a list. This list can then be read to produce a secondary structure prediction in the format of "*" and "(".

## Function I/O
As mentioned in the summary, there are two main steps to this program: filling out the dynamic table and reading/writing the backtrace. However, it would be beneficial to create a helper methods to make the code more readable.

1. `int calculateScore(int A, int B, std::string rnaStrand, std::vector<std::vector<int>> & dpTable)`
```
@param A/B -- index of nucleotides in the RNA sequence that will be checked to see if they are complimentary
@param rnaStrand -- this is the string representation of the RNA sequence to be analyzed
@param dpTable -- this is the dynamic programming table that will hold all the maximum scores at given indices
@return -- an int describing the max score between these indices
```
This helper function will determine the maximum score at two indices by taking in two "int" params for the indices, the RNA sequence to be analyzed, and the dynamic programming table that will be filled in. The maximum score is returned by finding the maximum score between all the possible subsequences between the given indices through the dynamic table.

2. `std::vector<std::vector<int>> createDPTable(std::string rnaStrand)`
```
@param rnaStrand -- the string representation of the RNA sequence to be analyzed
@return -- a table created as a std::vector<std::vector<int>> that logs all the maximum scores
```
This is the main dynamic programming function that calls the helper "calculateScore" method at every pair of indices. Storing the maximum scores allows for easy access to previously calculated scores, instead of having to recalculate them every iteration. This function will first initialize the entire NxN "matrix" (where N is the length of the passed rnaStrand) with 0s, and will then fill the matrix in a diagonal manner. The first two test cases implemented check to see if the "calculateScore" and "createDPTable" are correctly implemented by checking to see if the final score is as expected, along with the formed DP Table.

3. `std::string traceback(int start, int end, std::vector<std::vector<int>> dpTable, std::string rnaStrand)`
```
@param start/end -- designate the starting indices for the Nussinov algorithm (generally the first and last character of the RNA sequence)
@param dpTable -- the completed dynamic programming table created through the "createDPTable" function that stores all the maximum scores
@param rnaStrand -- the RNA sequence to be analyzed for secondary structure
@return -- an std::string representing the secondary structure using "*" and "()"
```
This function is called recursively to determine the traceback of the maximum calculated score of the dynamic programming table, located at the top right corner. The returned string is the most commonly used format of the Nussinov algorithm, which uses "()" to designate which nucleotides are bound to each other. The last test case checks to see if this function is correctly implemented by comparing the expected secondary structure output with the result from this function, especially on a larger RNA sequence. 

**We will continue to write more test cases to ensure that all edge cases are taken care of!**

## Data Description
Our test datasets were manually constructed to guarantee that expected output for each test case was correct. 
