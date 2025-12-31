// TC = O(n)  SC = O(log n)   (balanced tree) worst case O(n)


class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;

        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, l, mid - 1);
        root->right = buildBST(nums, mid + 1, r);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};
