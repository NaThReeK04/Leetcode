class Solution {
public:
    int helper(vector<string>&strs,int idx,int m,int n,vector<vector<vector<int>>>&dp){
        if(idx==strs.size())return 0;
        if(dp[idx][m][n]!=-1)return dp[idx][m][n];

        int zero=0,one=0;
        for(auto it:strs[idx]){
            if(it=='0')zero++;
            else one++;
        }

        int notTake=helper(strs,idx+1,m,n,dp);
        int Take=0;
        if(m>=zero&&n>=one){
            Take=1+helper(strs,idx+1,m-zero,n-one,dp);
        }
        return dp[idx][m][n]=max(notTake,Take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<vector<vector<int>>>dp(len,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs,0,m,n,dp);
    }
};