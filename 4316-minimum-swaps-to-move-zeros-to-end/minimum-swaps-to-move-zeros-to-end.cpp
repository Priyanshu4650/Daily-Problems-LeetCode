class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int countZero = count(nums.begin(), nums.end(), 0);
        int zero = 0;

        for(int i=nums.size() - 1; i >= nums.size() - countZero && i >= 0; i--) {
            zero += nums[i] == 0;
        }

        return countZero - zero;
    }
};