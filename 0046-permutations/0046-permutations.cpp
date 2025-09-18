class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&nums,int start){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,int>mpp;
        for(int i=start;i<nums.size();i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]=1;
                swap(nums[start],nums[i]);
                solve(ans,nums,start+1);
                swap(nums[start],nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(ans,nums,0);
        return ans;
    }
};