class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0;i<k;i++) {

            int ind = 0;
            int minValue = nums[0];
            for(int j=1;j<nums.size();j++) {
                if(nums[j] < minValue) {
                    ind = j;
                }
                minValue = min(minValue, nums[j]);
            }

            nums[ind] *= multiplier;
        }
        return nums;
    }
};