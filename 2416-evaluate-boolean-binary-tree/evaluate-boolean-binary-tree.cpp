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
    void postOrder(TreeNode *root, vector<int>& post) {
        if(root) {
            postOrder(root->left, post);
            postOrder(root->right, post);
            post.push_back(root->val);
        }
    }
public:
    bool evaluateTree(TreeNode* root) {
        if(!root) return false;
        
        vector<int> post;
        postOrder(root, post);

        stack<int> st;
        int i = 0;
        while(i < post.size()) {
            if(post[i] == 0 || post[i] == 1)
                st.push(post[i]);
            else if(post[i] == 2) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a | b);                
            }
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a & b);
            }
            i += 1;
        }

        return st.top();
    }
};