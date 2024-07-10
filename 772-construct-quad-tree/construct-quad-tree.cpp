/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool checkEqual(vector<vector<int>>& grid, int sr, int sc, int er, int ec)
    {
        int val = grid[sr][sc];

        for (int i=sr;i<=er;i++)
        {
            for (int j=sc;j<=ec;j++)
            {
                if (grid[i][j] != val)
                    return false;
            }
        }

        return true;
    }

    // Recursive function to construct tree.
    Node* construct(vector<vector<int>>& grid, int sr, int sc, int er, int ec)
    {
        // If all values are equal return.
        if (checkEqual(grid, sr, sc, er, ec))
            return new Node(grid[sr][sc], true);

        // Create root node with isLeaf as false.
        Node* root = new Node(1, false);

        /*
        topLeft row is from rs to half and col from sc to half
        topRight row is from rs to half and col from half + 1 to ec
        bottomLeft row is from half + 1 to end and col from sc to half
        bottomRight row is from half + 1 to end and col from sc to ec
        */

        root -> topLeft = construct(grid, sr, sc, (sr + er) / 2, (sc + ec) / 2);
        root -> topRight = construct(grid, sr, (sc + ec) / 2 + 1, (sr + er) / 2, ec);
        root -> bottomLeft = construct(grid, (sr + er) / 2 + 1, sc, er, (sc + ec) / 2);
        root -> bottomRight = construct(grid, (sr + er) / 2 + 1, (sc + ec) / 2 + 1, er, ec);

        return root;
    }
    Node* construct(vector<vector<int>>& grid) 
    {
        return construct(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }
};