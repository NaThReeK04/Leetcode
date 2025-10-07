class Solution {
public:
    int helper(vector<int>&nums,vector<vector<int>>&dp,int idx,int prev_idx,int n){
        if(idx==n)return 0;
        if(dp[idx][prev_idx+1]!=-1)return dp[idx][prev_idx+1];
        int notTake=helper(nums,dp,idx+1,prev_idx, n);
        int Take=INT_MIN;
        if(prev_idx==-1||nums[idx]>nums[prev_idx]){
            Take=1+helper(nums,dp,idx+1,idx,n);
        }
        return dp[idx][prev_idx+1]=max(notTake,Take);  
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(nums,dp,0,-1,n);
    }
};