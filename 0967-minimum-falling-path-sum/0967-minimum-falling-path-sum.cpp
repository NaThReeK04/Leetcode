class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (r < 0 || c < 0 || c >= matrix[0].size()) return INT_MAX;
        if (r == 0) return matrix[r][c];
        if (dp[r][c] !=-100000) return dp[r][c];
        
        int topleft = (c > 0) ? solve(r - 1, c - 1, matrix, dp) : INT_MAX;
        int up = solve(r - 1, c, matrix, dp);
        int topright = (c < matrix[0].size() - 1) ? solve(r - 1, c + 1, matrix, dp) : INT_MAX;
        return dp[r][c] = matrix[r][c] + min({topleft, up, topright});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -100000));
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, solve(n - 1, i, matrix, dp));
        }
        
        return ans;
    }
};
