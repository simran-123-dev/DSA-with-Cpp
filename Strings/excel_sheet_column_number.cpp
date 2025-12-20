// Problem: Excel Sheet Column Number
// Description: Convert an Excel column title (A, AB, ZY, etc.)
// into its corresponding column number.
// Approach: Base-26 conversion (left to right)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (int i = 0; i < columnTitle.length(); i++) {
            int value = columnTitle[i] - 'A' + 1;
            result = result * 26 + value;
        }

        return result;
    }
};
