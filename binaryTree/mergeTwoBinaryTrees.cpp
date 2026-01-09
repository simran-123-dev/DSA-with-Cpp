class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // case 1
        if (!root1) return root2;
        if (!root2) return root1;

        // case 2: both exist
        root1->val += root2->val;

        // merge children
        root1->left  = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
