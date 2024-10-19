class Solution {
public:
    string invert(string s){
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                s[i] = '0';
            }
            else{
                s[i] = '1';
            }
        }
        return s;
    }
    string reverse(string s){
        for(int i = 0; i < s.length() / 2; i++){
            swap(s[i], s[s.length() - 1 - i]);
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        while(--n){
            s = s + "1" + reverse(invert(s));
        }
        return s[k - 1];
    }
};