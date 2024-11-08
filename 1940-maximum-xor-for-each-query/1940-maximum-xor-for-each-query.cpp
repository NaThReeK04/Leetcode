class Solution
{
    public:
        vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
        {
            int n = nums.size();
            for (int i = 1; i < n; i++)
            {
                nums[i] = nums[i] ^ nums[i - 1];
            }
            int maxi = (1 << maximumBit) - 1;
            for (int i = n - 1; i >= 0; i--)
            {
                nums[i] = nums[i] ^ maxi;
            }
            reverse(nums.begin(), nums.end());
            return nums;
        }
};