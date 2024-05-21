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
    int minHeight(TreeNode *root, int h) {
        if (!root->left && !root->right) {
            return h;
        }
        int l = INT_MAX, r = INT_MAX;
        if (root->left) {
            l = minHeight(root->left, h + 1);
        }
        if (root->right) {
            r = minHeight(root->right, h + 1);
        }
        return min(l, r);
    }
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return minHeight(root, 1);
    }
};
