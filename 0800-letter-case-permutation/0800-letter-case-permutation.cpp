class Solution {
public:
    void solve(string s,string temp,vector<string>&ans){
        if(s.length()==0){
            ans.push_back(temp);
            return;
        }
        string op1=temp;
        string op2=temp;
        string op3=temp;
        char ch=s[0];
        if(isdigit(ch)){
            op3+=ch;
            s.erase(s.begin()+0);
            solve(s,op3,ans);
        }else{
            char ch1=(char)tolower(ch);
            char ch2=(char)toupper(ch);
            op1+=ch1;
            op2+=ch2;
            s.erase(s.begin()+0);
            solve(s,op1,ans);
            solve(s,op2,ans);
            
        }

    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string temp="";
        solve(s,temp,ans);
        return ans;
    }
};