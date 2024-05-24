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
    int helper(TreeNode *root, int sum) {
        if (!root) return sum;
        
        if (root->val % 2 == 0) {
            if (root->left) {
                if (root->left->left) {
                    sum += root->left->left->val;
                    cout << root->left->left->val << " ll ";
                }
                if (root->left->right) {
                    sum += root->left->right->val;
                    cout << root->left->right->val << " lr ";
                }
            }
            if (root->right) {
                if (root->right->left) {
                    sum += root->right->left->val;
                    cout << root->right->left->val << " rl ";
                }
                if (root->right->right) {
                    sum += root->right->right->val;
                    cout << root->right->right->val << " rr ";
                }
            }
        }
        
        sum = helper(root->left, sum);
        sum = helper(root->right, sum);
        
        return sum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        return helper(root, 0);
    }
};
