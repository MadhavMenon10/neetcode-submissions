/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node* ret = node;
        std::unordered_map<Node*, Node*> orig_to_new;
        std::queue<Node*> q;
        q.push(node);
        std::unordered_set<Node*> visited;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            Node* new_curr = new Node(curr->val);
            orig_to_new[curr] = new_curr;
            for (const auto& neighbor : curr->neighbors) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        for (const auto& [orig, new_node] : orig_to_new) {
            for (const auto& neighbor : orig->neighbors) {
                new_node->neighbors.push_back(orig_to_new[neighbor]);
            }
        }


       





        return orig_to_new[node];
        
    }
};
