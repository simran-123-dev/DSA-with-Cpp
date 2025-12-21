/*
    LeetCode 567: Permutation in String

    Problem:
    Given two strings s1 and s2, return true if s2 contains
    a permutation of s1 as a substring.

    Approach:
    Sliding Window + Frequency Array

    Time Complexity: O(n)
    Space Complexity: O(1)  (26 lowercase letters)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Frequency of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < n2; right++) {
            // add current char to window
            freq2[s2[right] - 'a']++;

            // maintain window size equal to s1 length
            if (right - left + 1 > n1) {
                freq2[s2[left] - 'a']--;
                left++;
            }

            // check if frequencies match
            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};
