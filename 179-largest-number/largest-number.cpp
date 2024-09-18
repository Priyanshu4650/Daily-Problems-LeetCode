class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Custom sort comparator to sort numbers in a way that forms the largest number
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string aStr = to_string(a);
            string bStr = to_string(b);
            return aStr + bStr > bStr + aStr;
        });

        // If the largest number is "0", the result is "0" (all numbers were zero)
        if (nums[0] == 0) {
            return "0";
        }

        // Construct the result by concatenating sorted numbers
        string res;
        for (int num : nums) {
            res += to_string(num);
        }

        return res;
    }
};
