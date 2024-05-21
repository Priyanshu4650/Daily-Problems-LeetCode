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
    bool check(TreeNode *root, int ch) {
        if(!root) return true;

        if(root->val != ch) return false;
        return check(root->left, ch) & check(root->right, ch);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return check(root, root->val);
    }
};