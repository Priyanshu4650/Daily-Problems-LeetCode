/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int helper(Node *root, int d) {
        if(!root) return d;
        int maxDepth = d;
        for(int i=0;i<root->children.size();i++) {
            maxDepth = max(maxDepth, helper(root->children[i], d + 1));
        }
        return maxDepth;
    }
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        return helper(root, 1);
    }
};