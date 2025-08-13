class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 1);  // prefix[0] = 1

        // Build prefix product
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] * nums[i];
        }

        // Build suffix product on the fly
        vector<int> ans(n);
        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            ans[i] = prefix[i] * suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
