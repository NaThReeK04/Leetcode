class Solution {
public:
    int maximumSwap(int num) {
        vector<int>ans;
        while(num!=0){
            int t=num%10;
            ans.push_back(t);
            num/=10;
        }
        int n=ans.size();
        reverse(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
                int maxi=*max_element(ans.begin()+i,ans.end());
                if(ans[i]!=maxi){
                   for(int j=n-1;j>=i;j--){
                        if(ans[j]==maxi){
                        swap(ans[i],ans[j]);
                        break;
                      }
                    }
                    break;
                }
            
        }
        int result=0;
        int p=n-1;
        for(int i=0;i<n;i++){
            result+=(ans[i]*pow(10,p--));
            
        }
        return result;

    }
};