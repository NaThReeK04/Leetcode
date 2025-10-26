class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty())return false;
                char temp=st.top();
                if(s[i]==')'&&temp!='(')return false;
                if(s[i]=='}'&&temp!='{')return false;
                if(s[i]==']'&&temp!='[')return false;
                st.pop();
            }
        }
        if(!st.empty())return false;
        return true;
    }
};