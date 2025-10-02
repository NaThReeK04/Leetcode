class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }else{
            return a[0]<b[0];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==1)return 1;
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int>temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1]>temp.back()){
                temp.push_back(envelopes[i][1]);
            }else{
                auto idx=lower_bound(temp.begin(),temp.end(),envelopes[i][1])-temp.begin();
                temp[idx]=envelopes[i][1];
            }
        }
        return temp.size();
    }
};