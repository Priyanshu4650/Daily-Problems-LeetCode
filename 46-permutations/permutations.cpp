class Solution {
    void helper(vector<int>& arr, set<vector<int>>& s, int ind) {
        if(ind == arr.size() - 1) {
            s.insert(arr);
            return;
        }
        for(int i=ind;i<arr.size();i++) {
            vector<int> temp(arr);
            swap(temp[i], temp[ind]);
            helper(temp, s, ind + 1);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> s;
        helper(nums, s, 0);
        vector<vector<int>> res;
        for(auto it : s) {
            res.push_back(it);
        }
        return res;
    }
};