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
    void recurse(TreeNode* root, int& num_good, int& max_seen) {
        if (root == nullptr) {
            return;
        }
        int new_max_left = max_seen;
        int new_max_right = max_seen;
        if (root->left) {
            if (root->left->val >= max_seen) {
                ++num_good;
                new_max_left = std::max(max_seen, root->left->val);
            } 
        }
        recurse(root->left, num_good, new_max_left);
        if (root->right) {
            if (root->right->val >= max_seen) {
                ++num_good;
                new_max_right = std::max(max_seen, root->right->val);
            }
        }
        recurse(root->right, num_good, new_max_right);
    }

    int goodNodes(TreeNode* root) {
        int num_good = 1;
        int max_seen = root->val;
        recurse(root, num_good, max_seen);
        return num_good;
    }
};
