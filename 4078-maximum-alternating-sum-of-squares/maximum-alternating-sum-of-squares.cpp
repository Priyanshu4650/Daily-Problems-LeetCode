class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](auto &a, auto &b) {
            return abs(a) < abs(b);
        });

        int i = 0;
        int j = nums.size() - 1;
        bool plus = true;
        long long sum = 0;

        while(i <= j) {
            if(plus) {
                sum += nums[j] * nums[j];
                j -= 1;
                plus = false;
            }
            else {
                sum -= nums[i] * nums[i];
                i += 1;
                plus = true;
            }
        }

        return sum;
    }
};