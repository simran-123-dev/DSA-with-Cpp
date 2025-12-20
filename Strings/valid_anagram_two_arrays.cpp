// Problem: Valid Anagram
// Description: Check whether string t is an anagram of string s.
// Approach: Use two frequency arrays of size 26 for lowercase letters.
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // lengths must be equal for anagram
        if (s.length() != t.length())
            return false;

        int a1[26] = {0};
        int a2[26] = {0};

        // count frequency of characters
        for (int i = 0; i < s.length(); i++) {
            a1[tolower(s[i]) - 'a']++;
            a2[tolower(t[i]) - 'a']++;
        }

        // compare both frequency arrays
        for (int i = 0; i < 26; i++) {
            if (a1[i] != a2[i])
                return false;
        }

        return true;
    }
};
