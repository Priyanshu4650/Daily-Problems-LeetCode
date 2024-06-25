class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++) {
            reverse(grid[i].begin(), grid[i].end());
            count += lower_bound(grid[i].begin(), grid[i].end(), 0) - grid[i].begin();
        }
        return count;
    }
};