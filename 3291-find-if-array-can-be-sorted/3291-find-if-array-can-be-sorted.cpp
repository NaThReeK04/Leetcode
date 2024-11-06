class Solution {
public:
  int printBits(int num) {
    int count=0;
    for (int i = 31; i >= 0; --i) {
        count+=((num >> i) & 1);
    }
    return count;
}
    bool canSortArray(vector<int>& nums) {
        vector<int>temp=nums;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]&&printBits(nums[j])==printBits(nums[j+1])){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        sort(temp.begin(),temp.end());
        if(temp==nums)return true;
        return false;

        
    }
};