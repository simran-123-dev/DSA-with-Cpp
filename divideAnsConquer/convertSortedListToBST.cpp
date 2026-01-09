class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = nullptr;

        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;

        ListNode* mid = findMiddle(head);
        TreeNode* root = new TreeNode(mid->val);

        if (head == mid) return root;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};
