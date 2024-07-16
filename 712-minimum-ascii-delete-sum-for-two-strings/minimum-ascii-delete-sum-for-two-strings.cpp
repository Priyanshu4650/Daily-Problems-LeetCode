class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i=1;i<=n;i++) {
            dp[i][0] += int(s1[i - 1]) + dp[i-1][0];
        }
        for(int i=1;i<=m;i++) {
            dp[0][i] += int(s2[i - 1]) + dp[0][i-1];
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }

        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n][m];
    }
};