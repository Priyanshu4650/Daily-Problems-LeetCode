class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>
        > mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = {i};
            } else {
                for (int j = 0; j < mp[nums[i]].size(); j++) {
                    if (i - mp[nums[i]][j] <= k) return true;
                }
                mp[nums[i]].push_back(i);
            }
        }
        return false;
    }
};