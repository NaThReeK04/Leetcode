class Solution {
public:
    int maxOperations(string s) {
        vector<int>oneCount;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')count++;
            oneCount.push_back(count);
        }
        int ans=0;
        for(int i=0;i<oneCount.size();i++){
            cout<<oneCount[i]<<" ";
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='0'&&s[i+1]=='0'&&i!=s.length()-1)continue;
            if(s[i]=='0')ans+=oneCount[i];
        }
        return ans;
    }
};