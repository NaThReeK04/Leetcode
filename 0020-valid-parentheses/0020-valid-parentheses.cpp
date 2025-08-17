class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }else if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(st.empty())return false;
                char temp=st.top();
                if(s[i]==')'&&temp!='(')return false;
                else if(s[i]=='}'&&temp!='{')return false;
                else if(s[i]==']'&&temp!='[')return false;
                else st.pop();
            }
        }
        if(!st.empty())return false;
        return true;

    }
};