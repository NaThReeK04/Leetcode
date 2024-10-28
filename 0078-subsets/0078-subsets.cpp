class Solution {
public:
    void helper(vector<int>&help,vector<vector<int>>&ans,vector<int>&nums,int i,int n){
        if(i==n){
            ans.push_back(help);
            return;
        }    
        helper(help,ans,nums,i+1,n);
        help.push_back(nums[i]);
        helper(help,ans,nums,i+1,n);
        help.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>help;
        helper(help,ans,nums,0,n);
        return ans;
    }
};