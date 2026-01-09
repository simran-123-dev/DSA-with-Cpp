class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* root, string path) {
        if (!root) return;

        // current node ko path me add karo
        path += to_string(root->val);

        // agar leaf node hai
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        // left / right ke liye arrow add karo
        path += "->";

        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
