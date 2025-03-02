class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        int j=0,k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=pos[j];
                j++;
            }
            else if(i%2==1){
                nums[i]=neg[k];
                k++;
            }

        }
        return nums;

    }
};














