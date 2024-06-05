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
    int count = 0;
    pair<int, int> helper(TreeNode *root) {
        if (!root) return {0, 0};
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        int sum = root->val + left.first + right.first;
        int nodecount = 1 + left.second + right.second;
        
        if(root->val == sum / nodecount)
            count += 1;

        return  {sum, nodecount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};
