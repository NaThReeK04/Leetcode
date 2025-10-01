class Solution {
public:
    int helper(vector<int>& cost, vector<int>& dp, int n) {
        if (n == 0) return cost[0];
        if (n == 1) return cost[1];
        if (dp[n] != -1) return dp[n];
        
        return dp[n] = min(helper(cost, dp, n - 1), helper(cost, dp, n - 2)) 
                        + (n == cost.size() ? 0 : cost[n]); 
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return helper(cost, dp, n);
    }
};
