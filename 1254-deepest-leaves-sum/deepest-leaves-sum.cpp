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
    int depth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    
    int helper(TreeNode *root, int currDepth, int maxDepth, int &sum) {
        if (!root) return 0;
        if (currDepth == maxDepth) {
            sum += root->val;
            return root->val;
        }
        return helper(root->left, currDepth + 1, maxDepth, sum) +
               helper(root->right, currDepth + 1, maxDepth, sum);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = depth(root);
        int sum = 0;
        helper(root, 1, maxDepth, sum);
        return sum;
    }
};
