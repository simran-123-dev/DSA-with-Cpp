// Longest Palindromic Substring
// Approach: Expand Around Center
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // 🔹 Case 1: Odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    start = left;
                    maxLen = currLen;
                }
                left--;
                right++;
            }

            // 🔹 Case 2: Even length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currLen = right - left + 1;
                if (currLen > maxLen) {
                    start = left;
                    maxLen = currLen;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};
