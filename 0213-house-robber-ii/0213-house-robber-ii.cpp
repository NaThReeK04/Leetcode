class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int start, int end) {
        if (end < start) return 0;
        if (end == start) return nums[start];
        if (end == start + 1) return max(nums[start], nums[start+1]);
        if (dp[end] != -1) return dp[end];

        dp[end] = max(nums[end] + helper(nums, dp, start, end-2),
                      helper(nums, dp, start, end-1));
        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        int case1 = helper(nums, dp1, 0, n-2);

        vector<int> dp2(n, -1);
        int case2 = helper(nums, dp2, 1, n-1);

        return max(case1, case2);
    }
};
