class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root) return;

        ans.push_back(root->val);   // root
        dfs(root->left);            // left
        dfs(root->right);           // right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
