class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* node, long minVal, long maxVal) {
        if (node == NULL) return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return check(node->left, minVal, node->val) &&
               check(node->right, node->val, maxVal);
    }
};
