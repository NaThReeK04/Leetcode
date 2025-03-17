class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(find(nums.begin(), nums.end(), target) == nums.end()) return {-1, -1};
        
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        
        int i = it1 - nums.begin();
        int j = it2 - nums.begin() - 1;
        
        return {i, j};
    }
};
