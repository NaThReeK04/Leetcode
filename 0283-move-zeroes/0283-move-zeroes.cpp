class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                copy.push_back(nums[i]);
            }
        }
        int m=nums.size()-copy.size();
        for(int i=0;i<m;i++){
            copy.push_back(0);
        }
        nums = copy;
    }
};
