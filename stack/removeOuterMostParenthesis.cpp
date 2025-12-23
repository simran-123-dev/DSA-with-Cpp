class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0) result += c;
                balance++;
            } else { // ')'
                balance--;
                if (balance > 0) result += c;
            }
        }
        return result;
    }
};
// Complexity

// Time: O(n)

// Space: O(1) (extra string only)
