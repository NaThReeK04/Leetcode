class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0,c2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        for(int i=0;i<n;i++){
            if(c1==0&&el2!=nums[i]){
                c1=1;
                el1=nums[i];
            }else if(c2==0&&el1!=nums[i]){
                c2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1)c1++;
            else if(nums[i]==el2)c2++;
            else{
                c1--;
                c2--;
            }
        }
        vector<int>ans;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1)cnt1++;
            if(nums[i]==el2)cnt2++;
        }
        int mini=floor(n/3);
        if(cnt1>mini)ans.push_back(el1);
        if(cnt2>mini)ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;

    }
};