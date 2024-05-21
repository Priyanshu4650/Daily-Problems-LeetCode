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
    int helper(TreeNode *root, int n) {
        if(!root->left && !root->right) return 1;
        int left = 0, right = 0;
        if(root->left)
            left = helper(root->left, n);
        if(root->right)
            right = helper(root->right, n);

        // cout << root->val << " " << left + right + 1 << " " << left << " " << right << endl;
        return left + right + 1;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return helper(root, 1);
    }
};