class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi=*max_element(candies.begin(),candies.end());
        int left=1,right=maxi;
        int res=0;
        while(left<=right){
            long long candiesCount=0;
            int mid=(left+right)/2;
            for(auto it:candies){
                candiesCount+=(it/mid);
            }
            if(candiesCount>=k){
                res=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return res;
    }
};