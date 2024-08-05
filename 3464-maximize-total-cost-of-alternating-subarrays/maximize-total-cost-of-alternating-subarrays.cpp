class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        long long addRes = nums[0];
        long long subRes = nums[0];

        for(int i=1;i<n;i++) {
            long long addTemp = max(addRes, subRes) + nums[i];
            long long subTemp = addRes - nums[i];

            addRes = addTemp;
            subRes = subTemp;
        }

        return max(addRes, subRes);
    }
};