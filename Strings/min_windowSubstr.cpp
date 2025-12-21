/*
    LeetCode 76: Minimum Window Substring

    Problem:
    Given strings s and t, return the minimum window substring of s
    such that every character in t (including duplicates) is included.

    Approach:
    Sliding Window + Hash Map

    Time Complexity: O(n)
    Space Complexity: O(1) (ASCII characters)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int required = freq.size();   // unique chars needed
        int formed = 0;

        unordered_map<char, int> window;
        int left = 0, right = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.length()) {
            char c = s[right];
            window[c]++;

            if (freq.count(c) && window[c] == freq[c]) {
                formed++;
            }

            // Try to shrink window
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (freq.count(leftChar) && window[leftChar] < freq[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
