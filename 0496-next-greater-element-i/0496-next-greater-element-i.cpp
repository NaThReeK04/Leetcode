class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) {
            bool found = false;
            int j = 0;
            while(j < nums2.size() && nums2[j] != nums1[i]) {
                j++;
            }
            for(j = j + 1; j < nums2.size(); j++) {
                if(nums2[j] > nums1[i]) {
                    ans.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }

            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};
