class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        for(auto num : nums) {
            operations += num % 3 != 0;
        }
        return operations;
    }
};
