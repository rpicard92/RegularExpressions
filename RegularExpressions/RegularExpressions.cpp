#include "RegularExpressions.h"

RegularExpressions::RegularExpressions() {};

/*
    matches regular expressions of whole words
    '.' is a subsistute for any character
    '*' N number of the preceeding character
*/
bool RegularExpressions::isMatch(std::string s, std::string p)
{
    // grap the size plus 1 to include an additional row in dp
    int sSize = s.size() + 1;
    int pSize = p.size() + 1;

    // dynamically build multi dimensional array
    int** dp = new int* [sSize];
    for (int index = 0; index < sSize; index++) {
        dp[index] = new int[pSize];
        // initialized all cells to 0
        for (int subIndex = 0; subIndex < pSize; subIndex++) {
            dp[index][subIndex] = 0;
        }
    }

    // initialized first cell value to true
    dp[0][0] = 1;

    
    /*
      Uses dynamic programming to exploit the structure of the problem. If you build an excel matrix of S v P (include empty case row/col) and
      fill in truth values, there is a recursive structure that can be found and exploited.

      Example:

            none    c   *   a   *   b
      none  1       0   1   0   1   0
      a     0       0   0   1   1   0
      a     0       0   0   1   1   0
      b     0       0   0   0   0   
    /
    */
  
    // catchs c*a*b* type structures and initialized them to the appropriate value, see below 
    int ii;
    for (int ii = 1; ii < pSize; ii++) {
        if (p[ii-1] == '*') {
            dp[0][ii] = dp[0][ii - 2];
        }
    }
    
    //loop through each element of s against each element of p (note DP is 1 great then s and p in each dimension. the first row and column account for if nothing is compared to each element)
    int i;
    int j;
    for (i = 1; i < sSize; i++) {
        for (j = 1; j < pSize; j++) {
            // if the elements are the same or a '.' then give teh bool value one row up and one row back 
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // if the p element is a star
            else if (p[j - 1] == '*') {
                // if j is atleast 2
                if (j >= 2) {
                    // give it the value of 2 columns back
                    dp[i][j] = dp[i][j - 2];
                    // if the previous p element equals the current s element, or the previous p element is a '.'  
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        // then give the bool value one row up or two columns back (if either is true)
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    }
                }
            }
        }
    }
    // return last value in matrix
    return dp[sSize - 1][pSize - 1];
 
};
