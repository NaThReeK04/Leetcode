class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        int result=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                result+=nums[i];
            }
            else{
                maxi=max(maxi,result);
                result=nums[i];
            }
        }
        maxi=max(maxi,result);
        return maxi;
    }
};