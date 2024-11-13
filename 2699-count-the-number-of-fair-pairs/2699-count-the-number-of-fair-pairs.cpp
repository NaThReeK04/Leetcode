class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            auto left=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto right=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            count+=(right-left);
        }
        return count;
    }
};