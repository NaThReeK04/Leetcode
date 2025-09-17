class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>&comb,vector<int>&nums,int idx,int k){
        if(idx==nums.size()){
            if(comb.size()==k){
                ans.push_back(comb);
            }
            return;
        }
        comb.push_back(nums[idx]);
        helper(ans,comb,nums,idx+1,k);
        comb.pop_back();
        helper(ans,comb,nums,idx+1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>comb;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        helper(ans,comb,nums,0,k);
        return ans;
    }
};