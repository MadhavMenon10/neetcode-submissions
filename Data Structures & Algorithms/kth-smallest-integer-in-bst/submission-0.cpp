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
    void inorder(TreeNode* root, std::vector<int>& trav) {
        if (root == nullptr) {
            return;
        }
        if (root != nullptr) {
            inorder(root->left, trav);
            trav.push_back(root->val);
            inorder(root->right, trav);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> traversal_result;
        inorder(root, traversal_result);
        return traversal_result[k-1];
    }
};
