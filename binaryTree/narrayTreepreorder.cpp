class Solution {
public:
    vector<int> ans;

    void dfs(Node* root) {
        if (!root) return;

        ans.push_back(root->val);          // ROOT
        for (auto child : root->children) // ALL CHILDREN
            dfs(child);
    }

    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};
