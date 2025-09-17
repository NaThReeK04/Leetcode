class Solution {
public:
    void helper(vector<vector<int>>&ans,vector<int>&comb,vector<int>&nums,vector<int>&freq){
        if(comb.size()==nums.size()){
            ans.push_back(comb);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=1;
                comb.push_back(nums[i]);
                helper(ans,comb,nums,freq);
                freq[i]=0;
                comb.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>comb;
        vector<int>freq(nums.size(),0);
        helper(ans,comb,nums,freq);
        return ans;
    }
};