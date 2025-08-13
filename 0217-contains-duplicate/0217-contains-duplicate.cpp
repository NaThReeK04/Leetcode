class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
          unordered_map<int,int>mpp;
          for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()||mpp[nums[i]]>=2){
                return true;
            }else if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]=1;
            }else{
                mpp[nums[i]]++;
            }
          }
          return false;
    }
};