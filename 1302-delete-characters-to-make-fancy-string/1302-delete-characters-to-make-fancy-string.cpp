class Solution {
public:
    string makeFancyString(string s) {
        int n=s.length();
        string temp="";
        for(int i=0;i<n;i++){
           if(temp.size()>=2&&temp[temp.size()-1]==s[i]&&temp[temp.size()-2]==s[i]){
            continue;
           }else{
            temp+=s[i];
           }
        }
        return temp;
        
    }
};