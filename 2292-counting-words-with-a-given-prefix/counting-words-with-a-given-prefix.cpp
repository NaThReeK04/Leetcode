class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.length();
        int m=words.size();
        int count=0;
        for(int i=0;i<m;i++){
            string temp=words[i].substr(0,n);
            if(temp==pref)count++;
        }
        return count;
    }
};