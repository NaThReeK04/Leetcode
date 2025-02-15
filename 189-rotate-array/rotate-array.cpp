class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int>dq;
        for(int i=0;i<nums.size();i++){
            dq.push_back(nums[i]);
        }
        for(int i=0;i<k;i++){
            int b=dq.back();
            dq.push_front(b);
            dq.pop_back();
        }
        int i=0;
        for(auto it=dq.begin();it!=dq.end();++it){
            nums[i]=*it;
            i++;
        }
    }
};