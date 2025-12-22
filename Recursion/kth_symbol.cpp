class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case
        if (n == 1) return 0;

        // Find parent in previous row
        int parent = kthGrammar(n - 1, (k + 1) / 2);

        // If k is odd -> left child
        if (k % 2 == 1) {
            return parent;
        }
        // If k is even -> right child
        else {
            return 1 - parent;
        }
    }
};


// tc=O(n)
