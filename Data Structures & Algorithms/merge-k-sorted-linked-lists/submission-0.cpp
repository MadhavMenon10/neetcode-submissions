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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode new_head;
        ListNode* curr = &new_head;
        auto cmp = [](ListNode* n1, ListNode* n2) {
            return n1->val > n2->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> min_heap;
        for (const auto& node : lists) {
            if (node != nullptr) {
                min_heap.push(node);
            }   
        }
        if (min_heap.empty()) {
            return nullptr;
        }
        while (!min_heap.empty()) {
            ListNode* top = min_heap.top();
            min_heap.pop();
            curr->next = top;
            top = top->next;
            if (top != nullptr) {
                min_heap.push(top);
            } 
            curr = curr->next;
        }
        return new_head.next;
    }
};
