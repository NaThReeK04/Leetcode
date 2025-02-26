class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count = 0;

        // Step 1: Find the candidate
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                ele = nums[i];  // Select new candidate when count is zero
                count = 1;
            } 
            else if (nums[i] == ele) {
                count++;  // Increase count if same as candidate
            } 
            else {
                count--;  // Decrease count if different from candidate
            }
        }

        // Step 2: Verify the candidate
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ele) {
                cnt++;
            }
        }

        // If candidate occurs more than half the time, return it, otherwise return -1
        if (cnt > (nums.size() / 2)) {
            return ele;
        }
        
        return -1;
    }
};
