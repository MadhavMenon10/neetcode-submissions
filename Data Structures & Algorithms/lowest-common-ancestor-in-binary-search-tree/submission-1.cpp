/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void construct_parent_map(TreeNode* root, std::unordered_map<TreeNode*, TreeNode*>& map_) {
        map_[root] = nullptr;
        std::queue<TreeNode*> queue_;
        queue_.push(root);
        while(!queue_.empty()) {
            TreeNode* curr = queue_.front();
            queue_.pop();
            if (curr != nullptr) {
                if (curr->left) {
                    map_[curr->left] = curr;
                    queue_.push(curr->left);
                }
                if (curr->right) {
                    map_[curr->right] = curr;
                    queue_.push(curr->right);
                }
            }
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_map<TreeNode*, TreeNode*> parents;
        construct_parent_map(root, parents);
        TreeNode* p_check = p;
        TreeNode* q_check = q;
        std::unordered_set<TreeNode*> visited;
        visited.insert(p_check);
        visited.insert(q_check);
        while (p_check != q_check) {
            if (p_check == nullptr || q_check == nullptr) {
                break;
            }
            p_check = parents[p_check];
            q_check = parents[q_check];
            if (visited.count(p_check)) {
                return p_check;
            }
            if (visited.count(q_check)) {
                return q_check;
            }
            visited.insert(p_check);
            visited.insert(q_check);
        }
        if (p_check == nullptr || q_check == nullptr) {
            return root;
        }
        return p_check;
    }
};
