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
    void reorderList(ListNode* head) {
        // hashmap index to node or sum
        ListNode* curr = head;
        std::unordered_map<int, ListNode*> index_map;
        int idx = 0;
        while (curr != nullptr) {
            index_map[idx++] = curr;
            curr = curr->next;
        }
        --idx;
        if (idx <= 1) {
            return;
        }
        for (int i = 0; i < idx; ++i) {
            index_map[i]->next = index_map[idx - i];
            if ((idx % 2 == 0 && i == idx - i) || (idx % 2 != 0 && i == idx/2 + 1)) {
                index_map[i]->next = nullptr;
                break;
            } else {
                index_map[idx - i]->next = index_map[i + 1];
            }
        }
    }
};
