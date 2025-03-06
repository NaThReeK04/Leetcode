class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            int count=nums[i];
            maxi=max(maxi,count);
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,nums[j]);
                count*=nums[j];
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};