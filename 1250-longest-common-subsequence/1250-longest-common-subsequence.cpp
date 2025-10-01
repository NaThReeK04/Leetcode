class Solution {
public:
    int helper(string &text1,string &text2,vector<vector<int>>&dp,int n,int m){
        if(n==0||m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(text1[n-1]==text2[m-1]){
            return dp[n][m]=1+helper(text1,text2,dp,n-1,m-1);
        }else{
            return dp[n][m]=max(helper(text1,text2,dp,n,m-1),helper(text1,text2,dp,n-1,m));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(text1,text2,dp,n,m);
    }
};