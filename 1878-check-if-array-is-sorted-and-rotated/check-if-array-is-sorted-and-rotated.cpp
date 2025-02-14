class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>nums1(nums);
        vector<int>dummy;
        sort(nums1.begin(),nums1.end());
        int idx=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1)return true;
        for(int i=idx+1;i<n;i++){
            dummy.push_back(nums[i]);
        }
        for(int i=0;i<=idx;i++){
            dummy.push_back(nums[i]);
        }
        if(dummy==nums1)return true;
        return false;

    }
};