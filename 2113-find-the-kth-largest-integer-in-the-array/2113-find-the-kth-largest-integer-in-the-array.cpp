class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const string &a, const string &b) {
            return a.size() == b.size() ? a > b : a.size() > b.size();
        });
        return nums[k-1];
    }
};

