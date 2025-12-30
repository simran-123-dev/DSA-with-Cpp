// O(n2) sc=O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        
        k = k % len;

        while (k--) {
            ListNode* prev = NULL;
            ListNode* curr = head;

            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            curr->next = head;
            head = curr;
        }

        return head;
    }
};

// optimized use cricular methon O(n)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1️⃣ length nikaalo + tail find karo
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // 2️⃣ k ko effective banao
        k = k % len;
        if (k == 0) return head;

        // 3️⃣ list ko circular bana do
        tail->next = head;

        // 4️⃣ new tail tak jao (len - k - 1 steps from head)
        int steps = len - k;
        ListNode* newTail = tail;
        while (steps--) {
            newTail = newTail->next;
        }

        // 5️⃣ break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};
