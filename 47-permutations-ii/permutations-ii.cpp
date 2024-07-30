class Solution {
    void backtrack(vector<int>& nums, set<vector<int>>& res, vector<int>& curr, vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            res.insert(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            visited[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums, res, curr, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, result, curr, visited);

        return vector<vector<int>>(result.begin(), result.end());
    }
};