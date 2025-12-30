// tc= O(n) sc= O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        int mid = len / 2;

        while (mid--) {
            head = head->next;
        }
        return head;
    }
};
