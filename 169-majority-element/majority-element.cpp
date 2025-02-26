class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                ele = nums[i];
                count = 1;
            }
            else if(nums[i] == ele) {
                count++;
            }
            else{
                count--;
            }
        }
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == ele) {
                cnt++;
            }
        }
        if(cnt > ceil(nums.size() / 2)) {
            return ele;
        }
        return -1;
    }
};
