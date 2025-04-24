class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int left=0,count=0;
        int s=unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            while(mpp.size()==s){
                count+=nums.size()-i;
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
        }
        return count;
        
    }
};