class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(!isalpha(s[i])){
                while(i<j&&!isalnum(s[i]))i++;
            }
            if(!isalpha(s[j])){
                while(i<j&&!isalnum(s[j]))j--;
            }
            char ch1=tolower(s[i]);
            char ch2=tolower(s[j]);
            if(ch1!=ch2)return false;
            i++;
            j--;
        }
        return true;
    }
};