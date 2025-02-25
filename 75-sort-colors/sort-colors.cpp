class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)zero++;
            if(nums[i]==1)one++;
            if(nums[i]==2)two++;
        }
        for(int i=0;i<n;i++){
             if(zero>0){
                nums[i]=0;
                zero--;
             }
             else if(zero==0&&one>0){
                nums[i]=1;
                one--;
             }
             else if(zero==0&&one==0&&two>0){
                nums[i]=2;
                two--;
             }
        }

    }
};