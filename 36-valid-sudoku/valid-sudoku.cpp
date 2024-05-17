class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for(int i=0;i<9;i++) {
            unordered_map<char, int> mp;
            for(int j=0;j<9;j++) {
                if(board[i][j] != '.') {
                    if(!mp[board[i][j]]) {
                        mp[board[i][j]] = 1;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        cout << "Checked Rows" << endl;

        // Check columns
        for(int j=0;j<9;j++) {
            unordered_map<char, int> mp;
            for(int i=0;i<9;i++) {
                if(board[i][j] != '.') {
                    if(!mp[board[i][j]]) {
                        mp[board[i][j]] = 1;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        cout << "Checked Columns" << endl;

        // Check 3x3 boxes
        for (int boxRow = 0; boxRow < 3; ++boxRow) {
            for (int boxCol = 0; boxCol < 3; ++boxCol) {
                unordered_map<char, int> mp;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        char current = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (current != '.') {
                            if (mp[current]++) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        cout << "Checked Boxes" << endl;

        return true;
    }
};