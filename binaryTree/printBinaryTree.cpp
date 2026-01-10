class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }

    void dfs(TreeNode* root, int r, int c, int gap,
             vector<vector<string>>& res) {
        if (!root) return;

        res[r][c] = to_string(root->val);

        if (root->left)
            dfs(root->left, r + 1, c - gap, gap / 2, res);

        if (root->right)
            dfs(root->right, r + 1, c + gap, gap / 2, res);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);

        int rows = h + 1;
        int cols = (1 << (h + 1)) - 1;

        vector<vector<string>> res(rows, vector<string>(cols, ""));

        dfs(root, 0, (cols - 1) / 2, (cols + 1) / 4, res);

        return res;
    }
};
