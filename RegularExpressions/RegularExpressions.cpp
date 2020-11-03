#include "RegularExpressions.h"

RegularExpressions::RegularExpressions() {};


bool RegularExpressions::isMatch(std::string s, std::string p)
{
    int sSize = s.size() + 1;
    int pSize = p.size() + 1;

    // dynamically build multi dimensionall array
    int** dp = new int* [sSize];
    for (int index = 0; index < sSize; index++) {
        dp[index] = new int[pSize];
        // initialized all cells to 0
        for (int subIndex = 0; subIndex < pSize; subIndex++) {
            dp[index][subIndex] = 0;
        }
    }

    // initialized first cell value
    dp[0][0] = 1;

    /*
    for (int iCatch = 1; iCatch < sSize; iCatch++) {
        if (p[iCatch-1] == '*') {
            dp[0][iCatch] = dp[0][iCatch - 2];
        }
    }
    */

    // loop through each element of s against each element of p
    int i;
    int j;
    for (i = 1; i < sSize; i++) {
        for (j = 1; j < pSize; j++) {
            // if the elements are the same or a '.' give the previous bool value to the dp cell 
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // if the p element is a star
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                // if the previous p element equals the current s element, or the previous p element is a '.' then give the previous bool value to the dp cell
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    // copy value to prevent out of scope issues
    bool val;
    if (dp[sSize - 1][pSize - 1] == 1) {
        val = 1;
    }
    else {
        val = 0;
    }
    return val;
 
};
