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
    int helper(TreeNode *root, int &mheight, int d) {
        if (!root) 
            return d;
        int leftDepth = helper(root->left, mheight, d + 1);
        int rightDepth = helper(root->right, mheight, d + 1);
        mheight = max(mheight, max(leftDepth, rightDepth));
        return mheight;
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root) 
            return 0;
        int mHeight = 0;
        helper(root, mHeight, 0); 
        return mHeight;
    }
};
