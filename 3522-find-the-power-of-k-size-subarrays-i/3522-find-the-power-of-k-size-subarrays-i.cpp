class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)return {nums[0]};
        vector<int>power;
        for(int i=0;i<n-k+1;i++){
            bool ye=false;
            int j;
            for(j=i;j<i+k-1;j++){
                if(nums[j]>=nums[j+1]){
                    power.push_back(-1);
                    ye=true;
                    break;
                }else if(nums[j]<nums[j+1]&&abs(nums[j]-nums[j+1])>1){
                    power.push_back(-1);
                    ye=true;
                    break;
                }
            }
            if(ye==false){
                power.push_back(nums[j]);
            }
        }
        
        return power;
        
    }
};