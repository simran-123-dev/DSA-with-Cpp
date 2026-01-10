class Solution {
public:
    void dfs(TreeNode* root, set<int>& s) {
        if (!root) return;

        s.insert(root->val);
        dfs(root->left, s);
        dfs(root->right, s);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(root, s);

        if (s.size() < 2) return -1;

        auto it = s.begin();
        advance(it, 1);   // 2nd smallest

        return *it;
    }
};
