class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if (m >= 0 && n >= 0 && obstacleGrid[m][n] == 1) return 0;
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        int top = solve(m - 1, n, dp, obstacleGrid);
        int left = solve(m, n - 1, dp, obstacleGrid);
        return dp[m][n] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp, obstacleGrid);
    }
};
