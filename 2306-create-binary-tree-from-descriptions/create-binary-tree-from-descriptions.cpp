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
    // Recursive function to build the binary tree from the descriptions
    void buildTree(TreeNode* root, unordered_map<int, pair<int, int>>& child) {
        if (!root || child.find(root->val) == child.end()) {
            return;
        }
        
        auto curr = child[root->val];
        
        if (curr.first != -1) {
            root->left = new TreeNode(curr.first);
            buildTree(root->left, child);
        }
        
        if (curr.second != -1) {
            root->right = new TreeNode(curr.second);
            buildTree(root->right, child);
        }
    }
    
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, int>> child;
        unordered_map<int, int> parent;
        set<int> s;

        // Populate child map and set of node values
        for (auto& description : descriptions) {
            s.insert(description[0]);
            s.insert(description[1]);

            parent[description[1]] = description[0];

            if (child.find(description[0]) == child.end()) {
                child[description[0]] = {-1, -1};
            }

            if (description[2] == 1) {
                child[description[0]].first = description[1];
            } else {
                child[description[0]].second = description[1];
            }
        }

        for(auto it : parent) {
            if(s.find(it.first) == s.end()) {
                continue;
            }
            else {
                s.erase(it.first);
            }
        }

        int rootNode = *s.begin();
        
        // Create the root node and build the tree
        TreeNode *root = new TreeNode(rootNode);
        buildTree(root, child);

        return root;
    }
};