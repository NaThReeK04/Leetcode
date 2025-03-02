class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)return nums.size();
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=temp.back()){
                temp.push_back(nums[i]);
            }
        }
        int maxi=1;
        int count=1;
        for(int i=1;i<temp.size();i++){
            if(temp[i]-temp[i-1]==1){
                count++;
                maxi=max(maxi,count);
            }else{
                count=1;
            }
        }
        return maxi;
    }
};