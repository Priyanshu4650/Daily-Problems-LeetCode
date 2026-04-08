class Solution {
    const int MOD = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(int i=0;i<queries.size();i++) {
            int idx = queries[i][0];
            int prevIdx = queries[i][0];
            while(idx < n && idx <= queries[i][1]) {
                long long temp = ((long long)nums[idx] * (long long)queries[i][3]) % MOD;
                nums[idx] = (int)temp;
                prevIdx = idx;
                idx += queries[i][2];
            }
        }

        int res = 0;
        for(auto num: nums) {
            res = res ^ num;
        }

        return res;
    }
};