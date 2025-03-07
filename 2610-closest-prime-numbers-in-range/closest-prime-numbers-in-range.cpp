class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int num1;
        int num2;
        int n=right;
        vector<int>prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=1;i<=n;i++){
            if(prime[i]==1){
                for(int j=2*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        vector<int>all;
        for(int i=left;i<=n;i++){
            if(prime[i]==1){
                all.push_back(i);
            }
        }
        // for(int i=0;i<all.size();i++){
        //     cout<<all[i]<<" ";
        // }
        if(all.size()<2)return {-1,-1};
        int mini=INT_MAX;
        for(int i=1;i<all.size();i++){
            int diff=all[i]-all[i-1];
            if(diff<mini){
                mini=diff;
                num2=all[i];
                num1=all[i-1];
            }
        }
        return {num1,num2};

    }
};