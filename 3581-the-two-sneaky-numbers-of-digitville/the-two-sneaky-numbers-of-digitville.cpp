class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num : nums) {
            mp[num] += 1;
        }
        vector<int> result;
        for(auto it: mp) {
            if(it.second == 2) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};