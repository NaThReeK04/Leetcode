class Solution {
public:
    void solve(int n, string& ans, string s, map<string, int>& mpp) {
        if (ans != "")
            return;
        if (s.size() == n) {
            if (mpp.find(s) == mpp.end()) {
                ans = s;
            }
            return;
        }
        solve(n, ans, s + '0', mpp);
        solve(n, ans, s + '1', mpp);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string ans;
        map<string, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        solve(n, ans, "", mpp);
        return ans;
    }
};