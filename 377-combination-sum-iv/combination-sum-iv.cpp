class Solution {
    int helper(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) {
            return 1;  // Found a combination
        }
        if (target < 0) {
            return 0;  // No valid combination
        }
        if (dp[target] != -1) {
            return dp[target];  // Return the cached result
        }

        int ways = 0;
        for (int num : nums) {
            ways += helper(nums, target - num, dp);
        }

        return dp[target] = ways;  // Cache the result
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);  // Initialize dp array with -1
        return helper(nums, target, dp);
    }
};