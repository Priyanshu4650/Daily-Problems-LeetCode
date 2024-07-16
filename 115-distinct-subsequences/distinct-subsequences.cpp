class Solution {
    int helper(string s, string t, vector<vector<int>>& dp, int sInd, int tInd) {
        if (tInd >= t.size()) {
            return 1; // Found a valid subsequence
        }
        if (sInd >= s.size()) {
            return 0; // Reached end of s, no more subsequences possible
        }

        if (dp[sInd][tInd] != -1) {
            return dp[sInd][tInd];
        }

        int res = helper(s, t, dp, sInd + 1, tInd); // Skip current character in s

        if (s[sInd] == t[tInd]) {
            res += helper(s, t, dp, sInd + 1, tInd + 1); // Match current character in s
        }

        dp[sInd][tInd] = res; // Memoize the result
        return res;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(s, t, dp, 0, 0);
    }
};
