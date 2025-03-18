class Solution {
public:
    int check(int val,vector<int>&bloomDay,int k){
        int count=0;
        int maxi=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=val){
                count++;
            }else{
                maxi+=count/k;
                count=0;
            }
        }
        maxi+=count/k;
        return maxi;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = (long long)m * k;
        if (totalFlowers > bloomDay.size()) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        //always analyse the while loop condition when to stop
        while(l<r){
            int mid=(l+r)/2;
            int sum=check(mid,bloomDay,k);
            if(sum<m)l=mid+1;
            else r=mid;
        }
        return l;    
    }
};