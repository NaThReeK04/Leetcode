class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0, count = 0;
        mpp[0] = 1; // Important: handles subarrays starting from index 0

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int search = sum - k;
            if (mpp.find(search) != mpp.end()) {
                count += mpp[search];
            }

            mpp[sum]++; // record prefix sum
        }
        return count;
    }
};
