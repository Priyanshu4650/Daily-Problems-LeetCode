class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        vector<vector<int>> rows(grid);
        vector<vector<int>> cols(grid);

        int countRows = 0;
        int countCols = 0;

        for(int i=0;i<grid.size();i++) {
            int low = 0;
            int high = grid[0].size() - 1;

            while(low <= high) {
                if(grid[i][low] != grid[i][high]) {
                    countRows += 1;
                }
                low += 1;
                high -= 1;
            }
        }

        for(int j=0;j<grid[0].size();j++) {
            int low = 0;
            int high = grid.size() - 1;

            while(low <= high) {
                if(grid[low][j] != grid[high][j]) {
                    countCols += 1;
                }
                low += 1;
                high -= 1;
            }
        }

        return min(countCols, countRows);
    }
};