class Solution {
public:
    unordered_set<int> st;

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // check complement
        if (st.count(k - root->val)) return true;

        // store current value
        st.insert(root->val);

        // check left or right subtree
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
