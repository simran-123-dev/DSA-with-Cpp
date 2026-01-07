class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // STEP 1: find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // STEP 2: reverse second half
        ListNode* second = reverseList(slow->next);
        slow->next = NULL;   // split list

        // STEP 3: merge two halves
        ListNode* first = head;
        while (second) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
};
