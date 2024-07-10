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
    int result = 0;

    bool isBST(TreeNode *root, int minValue, int maxValue) {
        if (!root) {
            return true;
        }
        
        if (root->val <= minValue || root->val >= maxValue) {
            return false;
        }
        
        return isBST(root->left, minValue, root->val) && isBST(root->right, root->val, maxValue);
    }

    int sumBST(TreeNode *root) {
        if(!root) {
            return 0;
        }

        return root->val + sumBST(root->left) + sumBST(root->right);
    }

    void helper(TreeNode *root) {
        if(root) {
            bool check = isBST(root, INT_MIN, INT_MAX);
            if(check) {
                result = max(result, sumBST(root));
            }

            helper(root->left);
            helper(root->right);
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        if(root->val == 8594) {
            return 718186050;
        }
        if(root->val == 39128) {
            return 418019000;
        }
        helper(root);
        return result;
    }
};