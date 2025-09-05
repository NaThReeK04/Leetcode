class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mpp;
        if (nums.size() % k != 0)
            return false;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        while (!mpp.empty()) {
            auto iter = mpp.begin();
            int num = iter->first;
            for (int i = 0; i < k; i++) {
                int curr = num + i;
                if (mpp[curr] == 0)
                    return false;
                mpp[curr]--;
                if (mpp[curr] == 0) {
                    mpp.erase(curr);
                }
            }
        }
        return true;
    }
};