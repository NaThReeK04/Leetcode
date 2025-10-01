class Solution {
public:
    int helper(vector<int>& coins, vector<vector<int>>& dp, int target,
               int idx) {
        if (target == 0)
            return 0;
        if (idx < 0)
            return INT_MAX;
        if (dp[idx][target] != -1){
            return dp[idx][target];
        }
        if(coins[idx]<=target){
            int nottake=helper(coins,dp,target,idx-1);
            int take=helper(coins,dp,target-coins[idx],idx);
            if(take!=INT_MAX)take=1+take;
            return dp[idx][target]=min(take,nottake);
        }else if(coins[idx]>target){
            return dp[idx][target]=helper(coins,dp,target,idx-1);
        }
        return -1;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans= helper(coins, dp, amount, n - 1);
        return ans==INT_MAX?-1:ans;
    }
};