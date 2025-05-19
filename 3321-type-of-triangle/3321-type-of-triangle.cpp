class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int>tri(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]<=nums[2])return "none";
        if(tri.size()==1)return "equilateral";
        if(tri.size()==2)return "isosceles";
        else return "scalene";
    }
};