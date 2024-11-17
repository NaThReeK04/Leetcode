class Solution {
public:
    int solve(int idx,vector<int>&dp,vector<int>&nums){
        if(idx==0){
            return nums[0];
        }
        if(idx<0){
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int pick=nums[idx]+solve(idx-2,dp,nums);
        int skip=solve(idx-1,dp,nums);
        return dp[idx]=max(skip,pick);
        
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,dp,nums);   
    }
};