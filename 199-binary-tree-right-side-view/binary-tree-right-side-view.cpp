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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            int t = q.size();

            for(int i=0;i<t-1;i++) {
                TreeNode *curr = q.front();

                if(curr->left) 
                    q.push(curr->left);
                if(curr->right) 
                    q.push(curr->right);
                
                q.pop();
            }

            res.push_back(q.front()->val);
            if(q.front()->left) 
                q.push(q.front()->left);
            if(q.front()->right) 
                q.push(q.front()->right);
            q.pop();
        }

        return res;
    }
};