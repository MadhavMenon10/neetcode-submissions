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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {\
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode head;
        ListNode* curr = &head;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int curr_sum = l1->val + l2->val + carry;
            ListNode* new_digit = new ListNode(curr_sum % 10);
            carry = curr_sum / 10;
            curr->next = new_digit;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
               curr->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            curr = curr->next;
            l1 = l1->next;
        } 
        while (l2 != nullptr) {
            curr->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            curr = curr->next;
            l2 = l2->next;
        }
        if (carry != 0) {
            curr->next = new ListNode(carry);
        }
        return head.next;
    }
};
