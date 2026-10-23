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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        int r = 0;
        ListNode* at_end = head;
        while (at_end->next != nullptr) {
            at_end = at_end->next;
            ++r;
        }
        if (r == 0) {
            return nullptr;
        }
        if (r - n + 1 == 0) {
            head = head->next;
            return head;
        }
        ListNode* curr = head;
        while (l + 1 != r - (n - 1)) {
            curr = curr->next;
            ++l;
        }
        curr->next = curr->next->next;
        return head;
    }
};
