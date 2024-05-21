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
    int findSecondMin(TreeNode* root, int minVal) {
        if (!root) return -1; // Indicates no second minimum found
        if (root->val > minVal) return root->val;
        int left = findSecondMin(root->left, minVal);
        int right = findSecondMin(root->right, minVal);
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1; // Indicates no second minimum found
        int minVal = root->val;
        return findSecondMin(root, minVal);
    }
};
