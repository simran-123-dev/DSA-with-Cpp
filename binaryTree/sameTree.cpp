// tc=O(n) sc= O(h)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base cases
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;

        // check left and right
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
