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
    void inOrder(TreeNode *root, vector<int>& in) {
        if(!root) return;
        inOrder(root->left, in);
        if(root)
            in.push_back(root->val);
        inOrder(root->right, in);
    }
    void helper(TreeNode *root, unordered_map<int, int>& mp) {
        if(!root) return;
        root->val = mp[root->val];
        helper(root->left, mp);
        helper(root->right, mp);
        return;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;

        vector<int> in;
        inOrder(root, in);
        unordered_map<int, int> mp;
        mp[in[in.size()-1]] = in[in.size()-1];

        for(int i=in.size()-2;i>=0;i--) {
            // cout << 
            mp[in[i]] = in[i] + in[i+1];
            in[i] += in[i+1];
        }

        for(int i=0;i<in.size();i++) {
            cout << in[i] << " ";
        }
        cout << endl;

        for(auto it : mp) {
            cout << it.first << " " << it.second << endl;
        }
        
        helper(root, mp);
        
        return root;
    }
};