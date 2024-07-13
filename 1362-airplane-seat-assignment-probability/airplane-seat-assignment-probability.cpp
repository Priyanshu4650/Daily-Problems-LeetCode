class Solution {
    double helper(int n, vector<double>& dp) {
        if(n == 1)
            return 1.0;
        if(n == 2)
            return 0.5;
        
        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = 1.0/n + ((n - 2.0) / n) * helper(n - 1, dp);
    }
public:
    double nthPersonGetsNthSeat(int n) {
        vector<double> dp(n + 1, -1);
        return helper(n, dp);
    }
};