class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int less=0;
        int equal=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)less++;
            else if(nums[i]==pivot)equal++;
        }
        int lidx=0;
        int eidx=less;
        int hidx=less+equal;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[lidx]=nums[i];
                lidx++;
            }else if(nums[i]>pivot){
                ans[hidx]=nums[i];
                hidx++;
            }else{
                ans[eidx]=nums[i];
                eidx++;
            }
        }
        return ans;
    }
};