class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        auto LIS = [&](int mask) {
            vector<int> dp;
            for (int x : nums) {
                if ((x & mask) > 0) {
                    auto it = lower_bound(dp.begin(), dp.end(), x);
                    if (it == dp.end())
                        dp.push_back(x);
                    else
                        *it = x;
                }
            }
            return (int)dp.size();
        };

        int ans = 0;

        for (int i = 0; i < 31; i++) {
            ans = max(ans, LIS(1 << i));
        }

        return ans;
    }
};