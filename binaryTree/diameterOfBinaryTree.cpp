class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        // update diameter
        diameter = max(diameter, leftHt + rightHt);

        return max(leftHt, rightHt) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
