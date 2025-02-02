class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>original=nums;
        sort(original.begin(),original.end());
        int n=nums.size();
        int shift=0;
        int i=1;
        while(i<n &&nums[i]>=nums[i-1]){
            i++;
        }
        shift=n-i;
        for(int j=0;j<n;j++){
            if(nums[j]!=original[(j+shift)%n]){
                return false;
            }
        }
        return true;
    }
};