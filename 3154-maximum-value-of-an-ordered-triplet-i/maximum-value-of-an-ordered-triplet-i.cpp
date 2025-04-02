class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=LLONG_MIN;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    long long val=(1LL*nums[i]-nums[j])*nums[k];
                    ans=max(ans,val);
                }
            }
        }
        return (ans<0)?0:ans;
    }
};