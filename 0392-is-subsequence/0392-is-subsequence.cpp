class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<string>>dp(n+1,vector<string>(m+1,""));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s[i-1];
                }else{
                    string temp1=dp[i-1][j];
                    string temp2=dp[i][j-1];
                    dp[i][j]=(temp1>temp2)?temp1:temp2;
                }
            }
        }
        return dp[n][m]==s;
    }
};