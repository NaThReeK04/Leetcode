class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0, count = 0;

        // First pass: Find the majority candidate
        for (int num : nums) {
            if (count == 0) {
                ele = num;
            }
            count += (num == ele) ? 1 : -1;
        }

        // Second pass: Verify the candidate (though not needed if guaranteed)
        int cnt = 0;
        for (int num : nums) {
            if (num == ele) {
                cnt++;
            }
        }

        return cnt > nums.size() / 2 ? ele : -1;
    }
};
