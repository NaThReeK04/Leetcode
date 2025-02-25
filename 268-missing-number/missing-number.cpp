class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // int sum= (n*(n+1))/2;
        // int s=0;
        // for(int i=0;i<n;i++){
        //     s+=nums[i];
        // }
        // return sum-s;
        int n=nums.size();
        int xor1=0;
        int xor2=0;
        for(int i=0;i<n;i++){
            xor1^=nums[i];
            xor2^=(i+1);
        }
        return xor1^xor2;
    }
};