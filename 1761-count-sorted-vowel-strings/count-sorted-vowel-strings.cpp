class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);

        while(n > 1) {
            dp[3] += dp[4];
            dp[2] += dp[3];
            dp[1] += dp[2];
            dp[0] += dp[1];
            n -= 1;
        }

        int res = 0;
        for(int i=0;i<5;i++) {
            res += dp[i];
        }

        return res;
    }
};