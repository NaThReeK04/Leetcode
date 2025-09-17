class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>&comb,vector<int>&nums,int idx){
        if(idx==nums.size()){
            ans.push_back(comb);
            return;
        }
        comb.push_back(nums[idx]);
        helper(ans,comb,nums,idx+1);
        comb.pop_back();
        while(idx+1<nums.size()&&nums[idx]==nums[idx+1]){
            idx++;
        }
        helper(ans,comb,nums,idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>comb;
        sort(nums.begin(),nums.end());
        helper(ans,comb,nums,0);
        return ans;
    }
};