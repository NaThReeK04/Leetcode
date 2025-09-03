class Solution {
public:
    int helper(vector<int>&nums,int goal){
        if(goal==0)return 0;
        int num;
        int reach=0;
        for(int i=0;i<goal;i++){
            reach=max(reach,i+nums[i]);
            if(reach>=goal){
                num=i;
                break;
            }
        }
        return 1+helper(nums,num);
    }
    int jump(vector<int>& nums) {
        return helper(nums,nums.size()-1);
    }
};