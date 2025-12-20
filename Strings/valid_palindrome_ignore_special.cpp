// Problem: Valid Palindrome
// Description: Check if a string is a palindrome by ignoring
// non-alphanumeric characters and case.
// Approach: Two pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int e = s.length() - 1;

        while (st < e) {

            // skip non-alphanumeric characters
            while (st < e && !isalnum(s[st])) {
                st++;
            }
            while (st < e && !isalnum(s[e])) {
                e--;
            }

            // compare characters (case-insensitive)
            if (tolower(s[st]) != tolower(s[e])) {
                return false;
            }

            st++;
            e--;
        }
        return true;
    }
};
