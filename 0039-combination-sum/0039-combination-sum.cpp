class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>&comb,vector<int>&candidates,int target,int i,int sum){
        if(sum==target){
            ans.push_back(comb);
            return;
        }
        if(sum>target||i>=candidates.size())return;
        comb.push_back(candidates[i]);
        helper(ans,comb,candidates,target,i,sum+candidates[i]);
        comb.pop_back();
        helper(ans,comb,candidates,target,i+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>comb;
        helper(ans,comb,candidates,target,0,0);
        return ans;
    }
};