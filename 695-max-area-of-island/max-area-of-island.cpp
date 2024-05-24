class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        stack<pair<int, int>> st;
        st.push({i, j});
        int m = grid.size();
        int n = grid[0].size();

        while (!st.empty()) {
            pair<int, int> t = st.top();
            st.pop();
            int r = t.first;
            int c = t.second;

            // Mark the cell as visited
            visited[r][c] = true;

            // Check neighbors and push unvisited neighboring cells onto the stack
            if (r + 1 < m && grid[r + 1][c] == 1 && !visited[r + 1][c]) {
                st.push({r + 1, c});
            }
            if (c + 1 < n && grid[r][c + 1] == 1 && !visited[r][c + 1]) {
                st.push({r, c + 1});
            }
            if (r - 1 >= 0 && grid[r - 1][c] == 1 && !visited[r - 1][c]) {
                st.push({r - 1, c});
            }
            if (c - 1 >= 0 && grid[r][c - 1] == 1 && !visited[r][c - 1]) {
                st.push({r, c - 1});
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    dfs(grid, visited, i, j);
                    // Calculate the area of the island starting from this cell
                    for (int p = 0; p < m; p++) {
                        for (int q = 0; q < n; q++) {
                            if (visited[p][q]) {
                                area++;
                                visited[p][q] = false; // Reset visited state for the next iteration
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
