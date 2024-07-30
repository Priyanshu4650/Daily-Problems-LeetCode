class Solution {
    void backtrack(vector<int>& nums, set<vector<int>>& result, vector<int>& curr, int idx) {
        if(idx == nums.size()) {
            result.insert(curr);
            return;
        }

        // not taking
        backtrack(nums, result, curr, idx + 1);

        // taking...
        curr.push_back(nums[idx]);
        backtrack(nums, result, curr, idx + 1);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        vector<int> curr;
        backtrack(nums, result, curr, 0);
        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};