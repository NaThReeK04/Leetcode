class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        if (nums.size() == 2) 
            return (nums[1] >= nums[0]) ? 1 : 0;
        
        if (nums.back() >= nums[0]) 
            return nums.size() - 1;

        vector<int> maxRight(nums.size());
        int maxVal = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; --i) {
            maxVal = max(maxVal, nums[i]);
            maxRight[i] = maxVal;
        }

        int i = 0, j = 1, ans = 0;
        while (j < nums.size()) {
            if (maxRight[j] >= nums[i]) {
                ans = max(ans, j - i);
            } else {
                while (i < j && nums[i] > maxRight[j]) {
                    ++i;
                }
            }
            ++j;
        }
        return ans;
    }
};

