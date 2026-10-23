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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> right_view;
        std::queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);
        while (!bfs_queue.empty()) {
            int size = bfs_queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = bfs_queue.front();
                bfs_queue.pop();
                if (i == size - 1) {
                    right_view.push_back(curr->val);
                }
                if (curr->left) {
                    bfs_queue.push(curr->left);
                }
                if (curr->right) {
                    bfs_queue.push(curr->right);
                }
            }
        }
        return right_view;
    }
};
