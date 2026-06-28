class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i=n-1;i>=n-k;i--) {
            if(mul == 0)
                mul = 1;
            // cout << nums[i] << " " << mul << endl;
            res += (long long)nums[i] * (long long)mul;
            mul -= 1;
        }
        
        return res;
    }
};