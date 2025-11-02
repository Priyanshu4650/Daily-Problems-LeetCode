class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = empty, 1 = wall, 2 = guard, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Mark walls
        for (auto& wall : walls)
            grid[wall[0]][wall[1]] = 1;

        // Mark guards
        for (auto& guard : guards)
            grid[guard[0]][guard[1]] = 2;

        // Directions → down, right, left, up
        vector<pair<int, int>> dirs = {{1,0}, {0,1}, {0,-1}, {-1,0}};

        for (auto& guard : guards) {
            int gx = guard[0];
            int gy = guard[1];

            // Explore all 4 directions
            for (auto [dx, dy] : dirs) {
                int x = gx + dx, y = gy + dy;
                while (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] != 1 && grid[x][y] != 2) {
                    // Mark as guarded
                    if (grid[x][y] == 0)
                        grid[x][y] = 3;
                    x += dx;
                    y += dy;
                }
            }
        }

        // Count unguarded cells (value 0)
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
};
