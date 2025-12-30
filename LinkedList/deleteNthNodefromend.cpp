// tc=O(n) sc= O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        // 1️⃣ length nikaalo
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // 2️⃣ agar head hi delete hona hai
        if (n == len) {
            return head->next;
        }

        // 3️⃣ node se pehle tak jao
        temp = head;
        for (int i = 1; i < len - n; i++) {
            temp = temp->next;
        }

        // 4️⃣ delete link
        temp->next = temp->next->next;

        return head;
    }
};
