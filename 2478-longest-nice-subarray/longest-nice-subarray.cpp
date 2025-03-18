class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int max_window_size=0;
        int currsum=0;
        int xorsum=0;
        while(right<n){
            currsum+=nums[right];
            xorsum^=nums[right];
            while(currsum!=xorsum){
                currsum-=nums[left];
                xorsum^=nums[left];
                left++;
            }
            max_window_size=max(max_window_size,right-left+1);
            right++;
        }
        return max_window_size;
    }
};