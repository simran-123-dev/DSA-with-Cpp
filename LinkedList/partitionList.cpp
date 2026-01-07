class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // dummy nodes
        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        ListNode* temp = head;

        while (temp != NULL) {
            if (temp->val < x) {
                small->next = temp;
                small = small->next;
            } else {
                large->next = temp;
                large = large->next;
            }
            temp = temp->next;
        }

        large->next = NULL;               // important
        small->next = largeDummy->next;   // join lists

        return smallDummy->next;           // new head
    }
};
