class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        int left=1,right=n-2;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])return nums[mid];
            else if(mid%2==1&&nums[mid]==nums[mid+1]||mid%2==0&&nums[mid]==nums[mid-1]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return -1;
    }
};