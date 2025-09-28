class Solution {
public:
    bool helper(vector<int>&nums,vector<vector<int>>&dp,int n,int sum){
        if(n==0){
            if(sum==0)return true;
            return false;
        }
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(nums[n-1]<=sum){
            return dp[n][sum]=helper(nums,dp,n-1,sum-nums[n-1])||helper(nums,dp,n-1,sum);
        }else if(nums[n-1]>sum){
            return dp[n][sum]=helper(nums,dp,n-1,sum);
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(nums,dp,n,target);
    }
};