class Solution {
public:
    static bool compare(pair<int,int>&a,pair<int,int>&b){
        return a.first>b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>ans;
        vector<int>res;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto c:mpp){
            ans.push_back(make_pair(c.second,c.first));
        }
        sort(ans.begin(),ans.end(),compare);
        for(int i=0;i<k;i++){
            res.push_back(ans[i].second);
        }
        return res;
    }
};