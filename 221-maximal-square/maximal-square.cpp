class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int oneCount = 0;

        for(int i=0;i<m;i++) {
            if(matrix[i][0] == '1') {
                oneCount += 1;
                dp[i][0] = 1;
            }
        }
        for(int i=0;i<n;i++) {
            if(matrix[0][i] == '1') {
                oneCount += 1;
                dp[0][i] = 1;
            }
        }

        int res = oneCount >= 1 ? 1 : 0;
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j - 1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return res * res;
    }
};