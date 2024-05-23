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
    TreeNode *helper(vector<int>& in, int st, int end) {
        if(st > end) {
            return NULL;
        }
        int mid = (st + end) / 2;

        TreeNode *root = new TreeNode (in[mid]);
        root->left = helper(in, st, mid - 1);
        root->right = helper(in, mid + 1, end);

        return root;
    }
    void inorder(TreeNode *root, vector<int>& in) {
        if(!root) return;
        inorder(root->left, in);
        if(root) {
            in.push_back(root->val);
        }
        inorder(root->right, in);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> in;
        inorder(root, in);
        return helper(in, 0, in.size() - 1);
    }
};