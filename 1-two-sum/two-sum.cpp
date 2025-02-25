class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int s=target-nums[i];
            if(mpp.find(s)!=mpp.end()&&mpp[s]!=i){
                return {i,mpp[s]};
            }
        }
        return {-1,-1};
        
    }
};