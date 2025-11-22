class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i]%3;
            ans+=min(num,(3-num));
        }
        return ans;
    }
};