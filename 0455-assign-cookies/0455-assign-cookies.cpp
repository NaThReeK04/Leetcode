class Solution {
public:
    int solve(int child, int greed, vector<int>& g, vector<int>& s, vector<int>& dp) {
        if (child < 0 || greed < 0) return 0;
        if (dp[greed] != -1) return dp[greed];

        return dp[greed] = (g[child] <= s[greed]) 
            ? 1 + solve(child - 1, greed - 1, g, s, dp) 
            : solve(child - 1, greed, g, s, dp);
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        vector<int> dp(m + 1, -1); 

        return solve(n - 1, m - 1, g, s, dp);
    }
};
