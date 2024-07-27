class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        int n = nums.size();

        for(int i=1;i<n;i++) {
            maxSum = max(maxSum, max(currSum + nums[i], nums[i]));
            currSum += nums[i];

            if(currSum < nums[i]) {
                currSum = nums[i];
            }
        }

        maxSum = max(maxSum, currSum);

        return maxSum;
    }
};