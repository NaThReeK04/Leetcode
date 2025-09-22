class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=INT_MIN;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            maxi=max(maxi,mpp[nums[i]]);
        }
        int ans=0;
        for(auto f:mpp){
            if(f.second==maxi){
                ans+=maxi;
            }
        }
        return ans;
    }
};