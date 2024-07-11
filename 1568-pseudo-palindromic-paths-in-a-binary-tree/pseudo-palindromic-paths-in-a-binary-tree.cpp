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
    int result = 0;
    void helper(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root->left && !root->right) {
            mp[root->val] += 1;
            cout << "ONCE\n";
            int oddCount = 0;
            for (auto it : mp) {
                if (it.second % 2 == 1) {
                    oddCount++;
                }

                if(oddCount > 1)    
                    break;
                cout << it.first << " " << it.second << endl;
            }

            if (oddCount <= 1) {
                result++;
            }

            cout << "END " << oddCount << " " << result << endl;
            mp[root->val] -= 1;
            return;
        }

        mp[root->val]++;

        if(root->left)
            helper(root->left, mp);
        if(root->right)
            helper(root->right, mp);

        mp[root->val]--;
        if (mp[root->val] == 0) {
            mp.erase(root->val);
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> mp;
        helper(root, mp);
        return result;
    }
};