class Solution {
public:
    bool solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(idx==0)return nums[0]==target;
        if(dp[idx][target]!=-1)return dp[idx][target];
        bool notpick=solve(idx-1,target,nums,dp);
        bool pick=false;
        if(nums[idx]<=target){
            pick=solve(idx-1,target-nums[idx],nums,dp);
        }
        return dp[idx][target]=notpick||pick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int temp=sum;
        sum=ceil(sum/2);
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        bool possible=solve(n-1,sum,nums,dp);
        if(possible){
            temp-=sum;
            if(temp==sum){
                return true;
            }
        }
        return false;
        
    }
};