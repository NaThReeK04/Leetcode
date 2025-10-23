class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        ans[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ans[i]=nums[i]*ans[i-1];
        }
        vector<int>result(n);
        int count=1;
        for(int i=n-1;i>=1;i--){
            result[i]=ans[i-1]*count;
            count*=nums[i];
        }
        result[0]=count;
        return result;
    }
};