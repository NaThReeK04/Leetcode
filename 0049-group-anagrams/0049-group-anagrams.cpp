class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(const auto &c:strs){
            string temp=c;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(c);
        }
        vector<vector<string>>res;
        for(auto p:mpp){
            res.push_back(p.second);
        }
        return res;
    }
};