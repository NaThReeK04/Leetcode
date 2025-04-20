class Solution {
public:
    static bool compare(pair<int,int>a,pair<int,int>b){
       return a.first>b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<pair<int,int>>ans;
        for(auto it:mpp){
            ans.push_back(make_pair(it.second,it.first));
        }
        sort(ans.begin(),ans.end(),compare);
        vector<int>final;
        for(int i=0;i<k;i++){
            final.push_back(ans[i].second);
        }
        return final;


    }
};