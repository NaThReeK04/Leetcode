class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        if(nums[0]==0)return false;
        int goal=nums.size()-1;
        int reach=0;
        for(int i=0;i<nums.size();i++){
            int tempReach=i+nums[i];
            if(tempReach==i&&reach<=i)return false;
            if(tempReach>reach){
                reach=tempReach;
            }
            if(reach>=goal&&i!=nums.size()-1)return true;
        }
        return false;
    }
};