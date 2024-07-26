class Solution {
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>> &grid, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;

        int count = 0;
        for(int i=0;i<4;i++) {
            int newX = dir[i][0] + r;
            int newY = dir[i][1] + c;

            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 1 && visited[newX][newY] == false) {
                count += dfs(grid, visited, newX, newY);
            }
        }

        return 1 + count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxArea = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    maxArea = max(maxArea, dfs(grid, visited, i, j));
                }
            }
        }

        return maxArea;
    }
};