/*
    LeetCode 424: Longest Repeating Character Replacement

    Problem:
    Given a string s and an integer k, you can replace at most k characters
    to make all characters in a substring the same.
    Return the length of the longest such substring.

    Approach:
    Sliding Window + Frequency Array

    Time Complexity: O(n)
    Space Complexity: O(1)  (26-size frequency array)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'A']++;

            // Track the most frequent character in the window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If replacements needed exceed k, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
