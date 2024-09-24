class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int size = INT_MAX;
        int currSum = 0;

        for(;r<n;r++) {
            currSum += nums[r];

            while(currSum >= target) {
                size = min(size, r - l + 1);
                currSum -= nums[l++];
            }
        }

        return size == INT_MAX ? 0 : size;
    }
};