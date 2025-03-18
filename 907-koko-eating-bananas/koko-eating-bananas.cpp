class Solution {
public:
    //use type cast (double) using a ceil function
    //always store the solution element if conditions 
    long long  check(int val,vector<int>&piles){
        long long  sum=0;
        for(int i=0;i<piles.size();i++){
            sum += ceil((double)piles[i] / val);

        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        //cout<<maxi<<endl;
        int left=1,right=maxi;
        int sol=-1;
        while(left<=right){
            int mid=(left+right)/2;
            long long  ans=check(mid,piles);
            //cout<<ans<<endl;
            if(ans<=h){
                sol=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return sol;
    }
};