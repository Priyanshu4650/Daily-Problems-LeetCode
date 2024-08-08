class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int sum = 0;
        int currSum = 0;

        // Calculate the initial sum of the array and the initial rotation function value
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            currSum += i * nums[i];
        }

        int maxSum = currSum;

        // Calculate subsequent rotation function values and find the maximum
        for (int i = 1; i < n; i++) {
            currSum = currSum + sum - n * nums[n - i];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};