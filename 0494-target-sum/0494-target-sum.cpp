class Solution {
public:
    int helper(vector<int>& nums, vector<vector<int>>& dp, int target, int n) {
        if (n == 0) {
            return target == 0 ? 1 : 0;
        }
        if (dp[n][target] != -1) return dp[n][target];

        if (nums[n-1] <= target) {
            return dp[n][target] = helper(nums, dp, target - nums[n-1], n-1)
                                 + helper(nums, dp, target, n-1);
        } else {
            return dp[n][target] = helper(nums, dp, target, n-1);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target=abs(target);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum<target||(sum + target) % 2 != 0) return 0;
        int search = (sum + target) / 2;
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(search+1, -1));
        return helper(nums, dp, search, n);
    }
};