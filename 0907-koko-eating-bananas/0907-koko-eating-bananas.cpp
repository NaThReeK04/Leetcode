class Solution {
public:
    long long check(vector<int>&piles,int num){
        long long n=0;
        for(int i=0;i<piles.size();i++){
            n+=ceil((double)piles[i]/num);
        }
        return n;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int k=*max_element(piles.begin(),piles.end());
        int low=1;
        int high=k;
        int ans=k;
        while(low<=high){
            int mid=(low+high)/2;
            long long r=check(piles,mid);
            if(r>h){
                low=mid+1;
            }else if(r<=h){
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};