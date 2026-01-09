class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);            // left
        dfs(root->right);           // right
        ans.push_back(root->val);   // root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
