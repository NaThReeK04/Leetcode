class Solution {
public:
    bool isPalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }

    void solve(string &s,vector<vector<string>>&ans,vector<string>&comb,int start){
        if(start==s.length()){ // partitioned whole string
            ans.push_back(comb);
            return;
        }

        for(int i=start;i<s.length();i++){
            if(isPalindrome(s,start,i)){  // check substring
                comb.push_back(s.substr(start,i-start+1));
                solve(s,ans,comb,i+1);    // move to next part
                comb.pop_back();          // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> comb;
        solve(s,ans,comb,0);
        return ans;
    }
};
