class Solution {
public:
    string compressedString(string word) {
        string comp="";
        vector<int>v(27,0);
        for(int i=0;i<word.size();i++){
            v[word[i]-'a']++;
            if(word[i]!=word[i+1]||v[word[i]-'a']==9){
                comp+=to_string(v[word[i]-'a']);
                comp+=word[i];
                v[word[i]-'a']=0;
            }
        }

        return comp;
        
    }
};