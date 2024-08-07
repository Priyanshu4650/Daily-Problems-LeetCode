class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) 
            return 0;

        sort(nums.begin(),nums.end());
        int maxDiff = INT_MIN;
        for(int i=0;i<n-1;i++) {
            maxDiff = max(maxDiff, nums[i + 1] - nums[i]);
        }

        return maxDiff;
    }
};