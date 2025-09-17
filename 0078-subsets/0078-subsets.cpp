class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>&help,vector<int>&nums,int i,int n){
        if(i==n){
            ans.push_back(help);
            return;
        }
        help.push_back(nums[i]);
        helper(ans,help,nums,i+1,n);
        help.pop_back();
        helper(ans,help,nums,i+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>help;
        helper(ans,help,nums,0,n);
        return ans;
    }
};