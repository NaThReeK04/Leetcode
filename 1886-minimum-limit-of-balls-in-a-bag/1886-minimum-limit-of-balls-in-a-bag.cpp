class Solution {
public:
    bool isPossible(vector<int>&nums,int maxOperations,int mid){
        int totOperations=0;
        for(auto it:nums){
            int Operations=(ceil((double)it/mid))-1;
            totOperations+=Operations;
            if(totOperations>maxOperations)return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxi=*max_element(nums.begin(),nums.end());
        int left=1,right=maxi;
        int ans=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(isPossible(nums,maxOperations,mid)){
                ans=min(ans,mid);
                right=mid-1;

            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};