// tc O(n) sc=O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (true) {
            ListNode* kth = prev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;

            ListNode* curr = prev->next;
            ListNode* next = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            prev = curr;
        }

        return dummy->next;
    }
};
