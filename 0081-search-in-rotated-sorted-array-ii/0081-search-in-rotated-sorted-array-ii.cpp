class Solution {
public:
    bool search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
};