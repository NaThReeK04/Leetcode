class Solution {
public:
    long long check(int m,vector<int>&nums){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            count+=ceil((double)nums[i]/m);
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int m=(l+r)/2;
            long long sum=check(m,nums);
            if(sum>threshold)l=m+1;
            else r=m-1;
        }
        return l;
    }
};