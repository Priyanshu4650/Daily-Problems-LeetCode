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
    void helper(TreeNode *root, int targetSum, vector<vector<int>>& res, vector<int>& temp, int sum) {
        // if(!root) return;
        sum += root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right) {
            if(targetSum == sum) {
                res.push_back(temp);
            }
        }

        if(root->left) {
            helper(root->left, targetSum, res, temp, sum);
        }
        if(root->right) {
            helper(root->right, targetSum, res, temp, sum);
        }
        
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root)  return res;

        vector<int> temp;
        // temp.push_back(root->val);
        helper(root, targetSum, res, temp, 0);

        return res;
    }
};