/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int len = getLen(head);
        k = k % len;
        if (k == 0) {
            return head;
        }

        ListNode* seclast = head;
        for (int i = 1; i < len - k; i++) {
            seclast = seclast->next;
        }

        ListNode* newHead = seclast->next;
        ListNode* tail = newHead;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = head;
        seclast->next = NULL;

        return newHead;
    }
};
