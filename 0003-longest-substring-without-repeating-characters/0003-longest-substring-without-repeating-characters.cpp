class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int maxi=0;
        int i=0,j=0;
        while(i<=j&&j<s.length()){
            if(mpp.find(s[j])==mpp.end()){
                mpp[s[j]]=1;
                maxi=max(maxi,j-i+1);
                j++;
            }else{
                mpp[s[j]]++;
                if(mpp[s[j]]>1){
                    while(mpp[s[j]]!=1){
                        mpp[s[i]]--;
                        i++;
                    }
                }
                maxi=max(maxi,j-i+1);
                j++;
            }
        }
        return maxi;
    }
};