class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num : nums) {
            mp[num] += 1;
        }
        
        int res = 0;
        for(auto ele : mp) {
            if(ele.second == 2) {
                res ^= ele.first;
            }
        }
        
        return res;
    }
};                              