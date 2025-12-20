// Problem: Excel Sheet Column Title
// Description: Convert a given column number to its corresponding
// Excel column title (A, B, ..., Z, AA, AB, ...).
// Approach: Base-26 conversion with adjustment (1-based indexing)
// Time Complexity: O(log26(n))
// Space Complexity: O(1)

#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--;                  // adjust for 1-based indexing
            int rem = columnNumber % 26;
            char ch = 'A' + rem;
            result = ch + result;            // prepend character
            columnNumber /= 26;
        }

        return result;
    }
};
