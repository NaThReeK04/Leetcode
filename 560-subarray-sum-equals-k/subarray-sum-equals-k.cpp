class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        vector<int>Prefix(n,0);
        Prefix[0]=nums[0];
        if(nums[0]==k)count++;
        unordered_map<int,int>mpp;
        mpp[nums[0]]=1;
        for(int i=1;i<n;i++){
            Prefix[i]=Prefix[i-1]+nums[i];
            if(Prefix[i]==k)count++;
            int num=Prefix[i]-k;
            if(mpp.find(num)!=mpp.end())count+=mpp[num];
            
            mpp[Prefix[i]]+=1;
            
        }
        return count;
    }
};