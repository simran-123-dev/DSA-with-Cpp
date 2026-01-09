class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        int sum = 0;

        // check if left child is a leaf
        if (root->left && 
            !root->left->left && 
            !root->left->right) {
            sum += root->left->val;
        }

        // recurse on both sides
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
