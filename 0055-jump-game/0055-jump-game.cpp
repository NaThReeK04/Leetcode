class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int goal = nums.size() - 1;

        for (int i = 0; i <= reach; i++) {
            reach = max(reach, i + nums[i]);
            if (reach >= goal) return true;
        }

        return false;
    }
};
