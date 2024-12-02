class Solution {
public:
    int solve(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (target == 0) return 0;  
        if (idx < 0) return INT_MAX; 
        if (dp[idx][target] != -1) return dp[idx][target];
        
        int notTake = solve(idx - 1, target, coins, dp); 
        int take = INT_MAX;
        if (coins[idx] <= target) {
            int res = solve(idx, target - coins[idx], coins, dp);
            if (res != INT_MAX) {
                take = 1 + res; 
            }
        }
        
        return dp[idx][target] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount + 1, -1)); 
        int result = solve(n - 1, amount, coins, dp);
        return result == INT_MAX ? -1 : result;
    }
};
