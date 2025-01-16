class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int XorValue=nums2[0];
        for(int i=1;i<n;i++){
            XorValue^=nums2[i];
        }
        int ans=0;
        if(n%2==0){
            for(int i=0;i<m;i++){
                ans^=XorValue;
            }
        }else if(n%2!=0){
            for(int i=0;i<m;i++){
                ans^=(nums1[i]^XorValue);
            }
        }
        return ans;
    }
};