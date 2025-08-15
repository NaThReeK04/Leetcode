class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0,maxf=0;
        int maxi=INT_MIN;
        unordered_map<char,int>mpp;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            maxf=max(maxf,mpp[s[j]]);
            while((j-i+1-maxf)>k){
                mpp[s[i]]--;
                i++;
            }
            maxi=max(maxi,j-i+1);

        }
        return maxi;
    }
};