class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int i,j=0;
        while(i<n&&j<m){
            if(str1[i]==str2[j]){
                i++;
                j++;
            }else if(str1[i]!=str2[j]){
                str1[i]=(((str1[i]-'a')+1)%26)+'a';
                if(str1[i]==str2[j]){
                    i++;
                    j++;
                }else if(str1[i]!=str2[j]){
                    i++;
                }
            }
            if(j==m)return true;
        }
        return false;
    }
};