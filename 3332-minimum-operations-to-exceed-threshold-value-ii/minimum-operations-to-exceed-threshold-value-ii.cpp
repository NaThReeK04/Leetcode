class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> m1(nums.begin(), nums.end());
        int count = 0;

        while (*m1.begin() < k) {
            auto it = m1.begin();
            long long num1 = *it;
            m1.erase(it);

            it = m1.begin();
            long long num2 = *it;
            m1.erase(it);

            long long num3 = (num1*2)+num2;
            m1.insert(num3);
            count++;
        }

        return count;
    }
};
