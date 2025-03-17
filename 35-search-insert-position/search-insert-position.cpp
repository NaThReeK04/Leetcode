class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        int f=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>target){
                right=mid-1;
            }else if(nums[mid]<=target){
                f=mid;
                left=mid+1;
            }
        }
        if(f==-1)return 0;
        return (nums[f]==target)?f:f+1;
    }
};