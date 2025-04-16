class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        long long count = 0;
        long long pairCount = 0;
        int n = nums.size();
        int left = 0;

        for (int right = 0; right < n; ++right) {
            int x = nums[right];
            long long oldFreq = mpp[x];
            long long oldPairs = (oldFreq * (oldFreq - 1)) / 2;
            mpp[x]++;
            long long newPairs = (mpp[x] * (mpp[x] - 1)) / 2;
            pairCount += (newPairs - oldPairs);

            while (pairCount >= k) {
                count += (n - right);

                int y = nums[left];
                long long oldFreqY = mpp[y];
                long long oldPairsY = (oldFreqY * (oldFreqY - 1)) / 2;
                mpp[y]--;
                long long newPairsY = (mpp[y] * (mpp[y] - 1)) / 2;
                pairCount -= (oldPairsY - newPairsY); 
                left++;
            }
        }

        return count;
    }
};
