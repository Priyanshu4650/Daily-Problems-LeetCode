class Solution {
    int helper(int n, int eggs, vector<int>& dp) {
        if (eggs == 0 || n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (eggs == 1) {
            return n;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        }

        int minDrops = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            int breaks = helper(i - 1, eggs - 1, dp); // Egg breaks
            int notBreaks = helper(n - i, eggs, dp);  // Egg does not break

            minDrops = min(minDrops, 1 + max(breaks, notBreaks));
        }

        return dp[n] = minDrops;
    }
public:
    int twoEggDrop(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, 2, dp);
    }
};