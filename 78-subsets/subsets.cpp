class Solution {
public:
    vector<vector<int>> output;
    int n, k;
    void backtrack(int first, vector<int> curr, vector<int>& nums) {
        // if the combination is done
        if (curr.size() == k) output.push_back(curr);
        for (int i = first; i < n; ++i) {
            // add i into the current combination
            curr.push_back(nums[i]);
            // use next integers to complete the combination
            backtrack(i + 1, curr, nums);
            // backtrack
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for (k = 0; k < n + 1; ++k) {
            vector<int> curr;
            backtrack(0, curr, nums);
        }
        return output;
    }
};