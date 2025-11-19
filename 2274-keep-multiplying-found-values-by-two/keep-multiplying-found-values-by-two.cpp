class Solution {
    bool isIn(int target, vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(nums[mid] == target) {
                return true;
            }
            else if(nums[mid] > target) {
                h -= 1;
            }
            else {
                l += 1;
            }
        }

        return false;
    }
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());

        while(isIn(original, nums)) {
            original *= 2;
        }

        return original;
    }
};