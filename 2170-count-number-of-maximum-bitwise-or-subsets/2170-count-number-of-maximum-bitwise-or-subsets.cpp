class Solution
{
    public:
        int subsets(vector<int> &nums, int maxor, int curror, int count, int start)
        {
            if (start == nums.size())
            {
                return (curror == maxor) ? 1 : 0;
            }
            int include = subsets(nums, maxor, curror | nums[start], count, start + 1);
            int exclude = subsets(nums, maxor, curror, count, start + 1);
            return include + exclude;
        }
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int maxor = 0;
        for (auto it: nums)
        {
            maxor |= it;
        }
        int ans = subsets(nums, maxor, 0, 0, 0);
        return ans;
    }
};