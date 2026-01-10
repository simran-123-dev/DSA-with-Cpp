class Solution {
public:
    int h;

    int height(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }

    void dfs(TreeNode* root, int r, int c, vector<vector<string>>& res) {
        if (!root) return;

        res[r][c] = to_string(root->val);

        int gap = 1 << (h - r - 1);

        if (root->left)
            dfs(root->left, r + 1, c - gap, res);

        if (root->right)
            dfs(root->right, r + 1, c + gap, res);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        h = height(root);

        int rows = h + 1;
        int cols = (1 << (h + 1)) - 1;

        vector<vector<string>> res(rows, vector<string>(cols, ""));

        dfs(root, 0, (cols - 1) / 2, res);

        return res;
    }
};
