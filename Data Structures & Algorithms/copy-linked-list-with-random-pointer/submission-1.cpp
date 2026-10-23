/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> orig_to_new;
        Node* new_head = new Node(head->val);
        Node* new_curr = new_head;
        orig_to_new[head] = new_head;
        Node* curr = head;
        curr = curr->next;
        while (curr != nullptr) {
            new_curr->next = new Node(curr->val);
            new_curr = new_curr->next;
            orig_to_new[curr] = new_curr;
            curr = curr->next;
        } 
        curr = head;
        while (curr != nullptr) {
            if (curr->random == nullptr) {
                orig_to_new[curr]->random = nullptr;
            } else {
                orig_to_new[curr]->random = orig_to_new[curr->random];
            }
            curr = curr->next;
        }



        return new_head;
    }
};
