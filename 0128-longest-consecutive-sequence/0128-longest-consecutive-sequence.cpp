class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1||nums.size()==0)return nums.size();
        int maxi=1;
        int count=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1==nums[i-1])count++;
            else if(nums[i]==nums[i-1])count=count;
            else count=1;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};