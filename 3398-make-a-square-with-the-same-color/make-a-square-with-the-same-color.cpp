class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                int black = 0;
                int white = 0;

                black += grid[i][j] == 'B';
                black += grid[i + 1][j] == 'B';
                black += grid[i][j + 1] == 'B';
                black += grid[i + 1][j + 1] == 'B';

                if(black != 2) {
                    return true;
                }
            }
        }

        return false;
    }
};