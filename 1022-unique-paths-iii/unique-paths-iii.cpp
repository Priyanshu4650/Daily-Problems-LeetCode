#include <vector>
#include <utility>
using namespace std;

class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    void backtrack(vector<vector<bool>>& visited, vector<vector<int>>& grid, pair<int, int> curr, pair<int, int> end, int& count) {
        if (curr == end) {
            // Check if all cells except start and end have been visited
            bool allVisited = true;
            int m = grid.size();
            int n = grid[0].size();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 0 && !visited[i][j]) {
                        allVisited = false;
                        break;
                    }
                }
                if (!allVisited) break;
            }
            if (allVisited) {
                count++;
            }
            return;
        }

        int x = curr.first;
        int y = curr.second;

        for (auto d : dir) {
            int newX = x + d.first;
            int newY = y + d.second;

            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] != -1 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                backtrack(visited, grid, {newX, newY}, end, count);
                visited[newX][newY] = false;    
            }
        }
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        pair<int, int> start, end;
        int emptyCells = 0; // Total number of empty cells '0' to visit
        
        // Find start and end positions, and count empty cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                } else if (grid[i][j] == 2) {
                    end = {i, j};
                } else if (grid[i][j] == 0) {
                    emptyCells++;
                }
            }
        }
        
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[start.first][start.second] = true;
        
        backtrack(visited, grid, start, end, count);
        
        return count;
    }
};
