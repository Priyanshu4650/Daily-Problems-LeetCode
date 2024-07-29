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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int ans = 0;

        while(!q.empty()) {
            int cnt = q.size();
            int start = q.front().second;
            int end = q.back().second;

            ans = max(ans, end - start + 1);

            for(int i=0;i<cnt;i++) {
                pair<TreeNode *, int> now = q.front();
                q.pop();

                long long idx = now.second;

                if(now.first->left) {
                    q.push({now.first->left, 2 * idx + 1});
                }
                if(now.first->right) {
                    q.push({now.first->right, 2 * idx + 2});
                }
            }
        }

        return ans;
    }
};