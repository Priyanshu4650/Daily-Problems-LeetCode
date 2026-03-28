class Solution {
    unordered_map<long long, int> memo;

    int dfs(vector<int>& nums, int target, int index, int currentXor) {
        if (index == nums.size()) {
            return (currentXor == target) ? 0 : INT_MIN;
        }

        long long key = ((long long)index << 32) | currentXor;
        if (memo.count(key)) return memo[key];

        // take element
        int take = dfs(nums, target, index + 1, currentXor ^ nums[index]);
        if (take != INT_MIN) take += 1;

        // skip element
        int skip = dfs(nums, target, index + 1, currentXor);

        return memo[key] = max(take, skip);
    }

public:
    int minRemovals(vector<int>& nums, int target) {
        int maxKept = dfs(nums, target, 0, 0);
        return maxKept < 0 ? -1 : nums.size() - maxKept;
    }
};