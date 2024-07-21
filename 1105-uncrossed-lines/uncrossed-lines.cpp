class Solution {
    int helper(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int i, int j) {
        if(i == nums1.size() || j == nums2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + helper(nums1, nums2, dp, i + 1, j + 1);
        }

        return dp[i][j] = max(helper(nums1, nums2, dp, i + 1, j + 1), max(helper(nums1, nums2, dp, i, j + 1), helper(nums1, nums2, dp, i + 1, j)));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(nums1, nums2, dp, 0, 0);
    }
};