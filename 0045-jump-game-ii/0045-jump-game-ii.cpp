class Solution {
public:
    int helper(vector<int>& nums, int goal, vector<int>& dp) {
        if (goal == 0) return 0;
        if (dp[goal] != -1) return dp[goal];

        int num = 0;
        int reach = 0;

        for (int i = 0; i < goal; i++) {
            reach = max(reach, i + nums[i]);
            if (reach >= goal) {
                num = i;
                break;
            }
        }

        return dp[goal] = 1 + helper(nums, num, dp);
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, n - 1, dp);
    }
};
