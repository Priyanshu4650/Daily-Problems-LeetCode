class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int i = 0;
        int j = 0;

        while(i < n) {
            while(j < n) {
                if(nums[j] > nums[i]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
                else {
                    // dp[j] = dp[i];
                }
                j += 1;
            }
            i += 1;
            j = i;
        }

        int res = 0;

        for(int i=0;i<n;i++) {
            res = max(res, dp[i]);
            cout << dp[i] << " ";
        }
        cout << endl;

        return res;
    }
};