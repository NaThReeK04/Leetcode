class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int search=target-nums[i];
            if(mpp.find(search)!=mpp.end()&&mpp[search]!=i)return {i,mpp[search]};
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};