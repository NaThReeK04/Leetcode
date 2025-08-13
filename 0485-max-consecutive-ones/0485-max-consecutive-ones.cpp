class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count;
        (nums[0]==1)?count=1:count=0;
        int maxi=max(count,0);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1&&nums[i-1]==1)count++;
            else if(nums[i]==1)count=1;
            else count=0;
            maxi=max(count,maxi);              
        }
        return maxi;

    }
};