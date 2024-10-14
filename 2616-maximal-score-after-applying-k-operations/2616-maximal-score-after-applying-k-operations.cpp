#include<cmath>
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        long long sum=0;
        for(int i=0;i<k;i++){
            int t=pq.top();
            pq.pop();
            sum+=t;
            t=ceil((double)t/3);
            pq.push(t);
        }
        return sum;   
    }
};