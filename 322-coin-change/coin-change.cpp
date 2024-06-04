class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        
        // Base case initialization
        for(int i = 0; i < amount + 1; i++) {
            dp[0][i] = amount + 1;
        }
        dp[0][0] = 0; // Base case
        
        // Dynamic programming
        for(int i = 1; i < coins.size() + 1; i++) {
            for(int j = 0; j < amount + 1; j++) {
                if(j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }
        
        return dp[coins.size()][amount] > amount ? -1 : dp[coins.size()][amount];
    }
};
