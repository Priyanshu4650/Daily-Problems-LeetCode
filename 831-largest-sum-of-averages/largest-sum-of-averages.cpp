class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefixSum(n + 1, 0);

        // Calculate prefix sum
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // DP table to store maximum sum of averages
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));

        // Base case: when k = 1, the max sum of averages is just the average of the first i elements
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = prefixSum[i] / i;
        }

        // Fill DP table
        for (int parts = 2; parts <= k; ++parts) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < i; ++j) {
                    dp[i][parts] = max(dp[i][parts], dp[j][parts - 1] + (prefixSum[i] - prefixSum[j]) / (i - j));
                }
            }
        }

        // The result is the maximum sum of averages for dividing the array into k parts
        return dp[n][k];
    }
};