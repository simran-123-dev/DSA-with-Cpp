class Solution {
public:
    vector<int> ans;

    void dfs(Node* root) {
        if (!root) return;

        for (auto child : root->children)  // CHILDREN FIRST
            dfs(child);

        ans.push_back(root->val);          // ROOT LAST
    }

    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }
};
