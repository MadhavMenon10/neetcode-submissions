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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> level_order_traversal;
        std::queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);
        while (!bfs_queue.empty()) {
            std::vector<int> level;
            int size = bfs_queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = bfs_queue.front();
                bfs_queue.pop();
                level.push_back(curr->val);
                if (curr->left != nullptr) {
                    bfs_queue.push(curr->left);
                }
                if (curr->right != nullptr) {
                    bfs_queue.push(curr->right);
                }
            }
            level_order_traversal.push_back(level);
        }
        return level_order_traversal;
    }
};
