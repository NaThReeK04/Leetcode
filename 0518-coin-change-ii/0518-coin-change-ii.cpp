class Solution {
public:
    int helper(vector<int>&coins,vector<vector<int>>&dp,int target,int idx){
        if(target==0)return 1;
        if(idx<0)return 0;
        if(dp[idx][target]!=-1)return dp[idx][target];
        if(coins[idx]<=target){
            return dp[idx][target]=helper(coins,dp,target-coins[idx],idx)+helper(coins,dp,target,idx-1);
        }else{
            return dp[idx][target]=helper(coins,dp,target,idx-1);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,dp,amount,n-1);
    }
};