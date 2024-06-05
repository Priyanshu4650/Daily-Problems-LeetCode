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
    void dfs(TreeNode* root, int& res, int mn, int mx){
        if(!root) return;
        res = max(res, max(abs(root->val - mn), abs(root->val - mx)));
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        dfs(root->left, res, mn, mx);
        dfs(root->right, res, mn, mx);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, res, root->val, root->val);
        return res;
    }
};
