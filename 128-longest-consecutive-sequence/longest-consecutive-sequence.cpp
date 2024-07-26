class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 1;

        for(auto num : nums) {
            int temp = num;
            if(s.find(temp - 1) == s.end()) {
                while(s.find(temp) != s.end()) {
                    temp += 1;
                }
            }
            result = max(result, temp - num);
        }

        return result;
    }
};