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
    TreeNode *helper(vector<int>& inorder, vector<int>& preorder, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preIndex]);
        preIndex++;
        
        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                inIndex = i;
                break;
            }
        }
        
        root->left = helper(inorder, preorder, preIndex, inStart, inIndex - 1);
        root->right = helper(inorder, preorder, preIndex, inIndex + 1, inEnd);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int preIndex = 0;
        return helper(inorder, preorder, preIndex, 0, inorder.size() - 1);
    }
};
