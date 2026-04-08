class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();

        vector<long long> oddCosts;
        vector<long long> evenCosts;

        // cost for odd indices
        for (int i = 1; i < n - 1; i += 2) {
            int required = max(nums[i - 1], nums[i + 1]) + 1;
            oddCosts.push_back(max(0, required - nums[i]));
        }

        // cost for even indices
        for (int i = 1 + (n % 2 == 0); i < n - 1; i += 2) {
            int required = max(nums[i - 1], nums[i + 1]) + 1;
            evenCosts.push_back(max(0, required - nums[i]));
        }

        // odd length → only one pattern
        if (n % 2 == 1) {
            return accumulate(oddCosts.begin(), oddCosts.end(), 0LL);
        }

        // even length → try all transitions
        long long curr = 0;
        for (auto &x : evenCosts) curr += x;

        long long ans = curr;

        for (int i = 0; i < evenCosts.size(); i++) {
            curr -= evenCosts[i];
            curr += oddCosts[i];
            ans = min(ans, curr);
        }

        return ans;
    }
};