// Problem: Longest Substring Without Repeating Characters
// Description: Find the length of the longest substring
// without duplicate characters.
// Approach: Sliding Window with frequency array
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int freq[256] = {0};   // to track characters in current window
        int left = 0;          // window start
        int maxLen = 0;        // maximum length found

        for (int right = 0; right < s.length(); right++) {

            freq[s[right]]++;

            // shrink window if duplicate character found
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            // update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
