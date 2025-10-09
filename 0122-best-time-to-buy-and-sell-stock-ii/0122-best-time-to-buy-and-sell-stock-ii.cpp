class Solution {
public:
    int helper(vector<int>& prices, vector<vector<int>>& dp, int idx, int canBuy, int n) {
        if (idx == n) return 0; // no days left

        if (dp[idx][canBuy] != -1) return dp[idx][canBuy];

        if (canBuy) {
            // Option 1: Buy the stock
            int buy = -prices[idx] + helper(prices, dp, idx + 1, 0, n);
            // Option 2: Skip buying
            int skip = helper(prices, dp, idx + 1, 1, n);
            return dp[idx][canBuy] = max(buy, skip);
        } else {
            // Option 1: Sell the stock
            int sell = prices[idx] + helper(prices, dp, idx + 1, 1, n);
            // Option 2: Skip selling (keep holding)
            int hold = helper(prices, dp, idx + 1, 0, n);
            return dp[idx][canBuy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(prices, dp, 0, 1, n); // start at day 0, canBuy = true
    }
};
