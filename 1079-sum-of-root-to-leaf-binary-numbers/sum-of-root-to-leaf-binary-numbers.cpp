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
    int helper(TreeNode *root, int curr) {
        if (!root) {
            return 0;
        }
        curr = curr * 2 + root->val;
        if (!root->left && !root->right) {
            return curr;
        }
        return helper(root->left, curr) + helper(root->right, curr);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};
