class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)mpp[nums[i]]=i;
        bool found=true;
        while(found){
            if(mpp.find(original)!=mpp.end()){
                original*=2;
            }else{
                found=false;
            }
        }
        return original;
    }
};