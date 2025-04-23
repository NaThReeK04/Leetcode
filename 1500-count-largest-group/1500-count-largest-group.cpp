class Solution {
public:
    static bool compare(pair<int,int>a,pair<int,int>b){
        return a.first>b.first;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mpp;
        for(int i=1;i<=n;i++){
            string temp=to_string(i);
            int sum=0;
            for(auto it:temp){
                sum+=(it-'0');
            }
            mpp[sum]++;
        }
        vector<pair<int,int>>ans;
        for(auto it:mpp){
            ans.push_back(make_pair(it.second,it.first));
        }
        sort(ans.begin(),ans.end(),compare);
        int count=1;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i].first==ans[i+1].first){
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};