/*
LeetCode 241 - Different Ways to Add Parentheses

Problem:
Given a string expression consisting of numbers and operators (+, -, *),
return all possible results from computing all the different ways to group
numbers and operators using parentheses.

Approach (Recursion + Divide & Conquer):
- Iterate through the expression.
- Whenever an operator is found, split the expression into:
    left substring  (before operator)
    right substring (after operator)
- Recursively compute all possible results for left and right parts.
- Combine each left result with each right result using the current operator.
- Base Case:
    If no operator is found in the expression, it is a single number.
    Convert it to integer using stoi() and return.

Time Complexity:
- Exponential (approximately Catalan number growth),
  because all possible binary expression trees are generated.

Space Complexity:
- Exponential:
  - recursion stack
  - storage of all possible results
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression[i];

            // If operator found, split expression
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine results
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') result.push_back(l + r);
                        else if (ch == '-') result.push_back(l - r);
                        else result.push_back(l * r);
                    }
                }
            }
        }

        // Base case: expression is a number
        if (result.empty()) {
            result.push_back(stoi(expression)); // string → integer
        }

        return result;
    }
};
