class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(auto num : nums) {
            freq[num] += 1;
        }
        vector<int> res;
        for(auto it : freq) {
            if(n / 3 < it.second)
                res.push_back(it.first);
        }
        return res;
    }
};