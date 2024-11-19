class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=INT_MIN;
        unordered_map<int,int>mpp;
        int n=nums.size();
        long long windowsize=0;
        for(int i=0;i<k;i++){
            windowsize+=nums[i];
            mpp[nums[i]]++;
        }
        bool one=true;
        if(mpp.size()!=k)one=false;
        if(one){
            ans=max(ans,windowsize);
        }
        for(int i=k;i<n;i++){
            windowsize-=nums[i-k];
            mpp[nums[i-k]]--;
            windowsize+=nums[i];
            mpp[nums[i]]++;
            if(mpp[nums[i-k]]==0)mpp.erase(nums[i-k]);
            if(mpp.size()==k){
                ans=max(ans,windowsize);
            }

        }
        return (ans==INT_MIN)?0:ans;

    }
};