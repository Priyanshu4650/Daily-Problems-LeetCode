class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }

        // Initialize the dp arrays
        vector<int> sell(n, 0);   // Max profit when selling on day i
        vector<int> buy(n, 0);    // Max profit when buying on day i
        vector<int> cooldown(n, 0); // Max profit when cooling down on day i

        // Initial conditions
        buy[0] = -prices[0];      // If we buy on day 0, the profit is -prices[0]
        sell[0] = 0;              // No stock to sell on day 0, profit is 0
        cooldown[0] = 0;          // No cooldown on day 0, profit is 0

        for (int i = 1; i < n; ++i) {
            // Update buy, sell, and cooldown values
            buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
            cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
        }

        // The maximum profit will be in either the sell state or the cooldown state on the last day
        return max(sell[n - 1], cooldown[n - 1]);
    }
};