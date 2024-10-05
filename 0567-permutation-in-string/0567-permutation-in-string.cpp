class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if (n > m) return false;
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s1[i]]++;
        }
        unordered_map<char,int>temp;
        temp=mpp;
        for(int i=0;i<=m-n;i++){
            for(int j=i;j<i+n;j++){
                if(mpp.find(s2[j])!=mpp.end()){
                    mpp[s2[j]]--;
                }
            }
            bool we=false;
            for(auto it:mpp){
                if(it.second!=0){
                    we=true;
                    break;
                }
            }
            if(we==true){
                mpp=temp;
            }else{
                return true;
            }
        }
        return false;

    }
};