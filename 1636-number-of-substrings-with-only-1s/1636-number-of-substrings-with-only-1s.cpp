class Solution {
public:
    #define MOD 1000000007
    int numSub(string s) {
        long long ans=0;
        long long count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans=(ans+((count+1)*count)/2)%MOD;
                count=0;
            }else{
                count++;
            }
        }
        ans=(ans+((count+1)*count)/2)%MOD;
        return ans;
    }
};