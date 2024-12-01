class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            sum+=nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--){
            int num=sum-nums[i];
            mpp[nums[i]]--;
            if(num%2==0){
                if(mpp.find(num/2)!=mpp.end()&&mpp[num/2]>0){
                    return nums[i];
                }
            }
            mpp[nums[i]]++;
        }
        return -1;
    }
};