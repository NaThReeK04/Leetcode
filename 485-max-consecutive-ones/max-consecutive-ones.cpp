class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1&&nums[0]==0)return 0;
        if(nums.size()==2&&nums[0]==0&&nums[1]==0)return 0;
        int count=1;
        int maxi=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1){
                if(nums[i-1]==1){
                    count++;
                }
            }else if(nums[i]==0){
                maxi=max(maxi,count);
                count=1;
            }
        }
        maxi=max(maxi,count);
        return maxi;
    }
};