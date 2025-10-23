class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string>ans;
        while(ss>>word){
            ans.push_back(word);
        }
        string result="";
        for(int i=ans.size()-1;i>=0;i--){
            result+=ans[i];
            if(i!=0){
                result+=" ";
            }
        }
        return result;
    }
};