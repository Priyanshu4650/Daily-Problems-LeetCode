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
    void helper(TreeNode *root, int targetSum, long long sum) {
        sum += root->val;
        if(targetSum == sum) {
            count += 1;
            cout << root->val << endl;
        }
        if(root->left) {
            helper(root->left, targetSum, sum);
        }
        if(root->right) {
            helper(root->right, targetSum, sum);
        }
    }
    void psold(TreeNode* root, int targetSum) {
        if(!root)  return;
        helper(root, targetSum, 0);
    }

    void preOrder(TreeNode *root, int targetSum) {
        cout << root->val << " " << targetSum << endl;
        if(root->left) {
            preOrder(root->left, targetSum);
            psold(root->left, targetSum);
        }
        if(root->right) {
            preOrder(root->right, targetSum);
            psold(root->right, targetSum);
        }
    }
public:
    int count = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        psold(root, targetSum);
        preOrder(root, targetSum);
        return count;
    }
};