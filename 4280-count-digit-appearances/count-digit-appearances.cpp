class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(auto num: nums) {
            while(num > 0) {
                count += digit == num % 10;
                num /= 10;
            }
        }
        return count;
    }
};