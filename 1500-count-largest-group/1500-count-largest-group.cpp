class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        int maxi=-1;
        for(int i=1;i<=n;i++){
            string temp=to_string(i);
            int sum=0;
            for(auto it:temp){
                sum+=(it-'0');
            }
            mpp[sum]++;
            maxi=max(maxi,mpp[sum]);
        }
        int count=0;
        for(auto it:mpp){
            if(it.second==maxi)count++;
        }
        return count;
    }
};