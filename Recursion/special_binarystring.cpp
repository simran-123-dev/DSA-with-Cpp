/*
LeetCode 761 - Special Binary String

Problem:
Given a special binary string s, you can swap two consecutive non-empty
special substrings any number of times.
Return the lexicographically largest string possible.

Key Observations:
1. A special binary string always has:
   - equal number of '1's and '0's
   - in every prefix: count(1) >= count(0)

2. Every special string can be written as:
   1 + (inner special string) + 0

Approach (Recursion + Divide & Conquer):
- Split the string into top-level special substrings using a balance counter.
- For each substring:
    - Remove outer '1' and '0'
    - Recursively make the inner part lexicographically largest
    - Add back outer '1' and '0'
- Sort all processed substrings in descending order.
- Concatenate them to form the final answer.

Time Complexity:
- Exponential in worst case (due to recursion + sorting substrings)

Space Complexity:
- Exponential (recursion stack + substring storage)
*/

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;   // stores top-level special substrings
        int balance = 0;        // balance of 1s and 0s
        int start = 0;          // start index of current substring

        // STEP 1: Split string into top-level special substrings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') balance++;
            else balance--;

            // when balance becomes 0, we found a special substring
            if (balance == 0) {
                // take substring excluding outer '1' and '0'
                string inner = s.substr(start + 1, i - start - 1);

                // recursively process inner part
                string processed = makeLargestSpecial(inner);

                // add outer '1' and '0' back
                parts.push_back("1" + processed + "0");

                // move start to next position
                start = i + 1;
            }
        }

        // STEP 2: Sort substrings in descending order
        sort(parts.begin(), parts.end(), greater<string>());

        // STEP 3: Concatenate all parts
        string result = "";
        for (string &p : parts) {
            result += p;
        }

        return result;
    }
};
