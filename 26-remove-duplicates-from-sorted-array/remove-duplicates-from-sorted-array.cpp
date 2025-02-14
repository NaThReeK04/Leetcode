class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         vector<int>vec;
         vec.push_back(nums[0]);
         int n=nums.size();
         for(int i=1;i<n;i++){
            if(vec.back()!=nums[i]){
                vec.push_back(nums[i]);
            }
         }
         for(int i=0;i<vec.size();i++){
            nums[i]=vec[i];
         }
         return vec.size();
    }
};