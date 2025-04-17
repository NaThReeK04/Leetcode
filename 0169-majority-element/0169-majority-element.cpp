class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ele)count++;
            else count--;
            if(count==0){ele=nums[i];count=1;}
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele)c++;
        }
        if(c>=(nums.size()/2))return ele;
        return -1;
    }
};