class Solution {
public:
    void solve(vector<string>& ans, string digits, string& temp,
               unordered_map<int, string> mpp, int start) {
        if (start == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string t = mpp[digits[start] - '0'];
        for (int j = 0; j < t.size(); j++) {
            temp.push_back(t[j]);
            solve(ans, digits, temp, mpp, start + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        unordered_map<int, string> mpp = {{2, "abc"}, {3, "def"}, {4, "ghi"},
                                          {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                          {8, "tuv"}, {9, "wxyz"}};
        string temp = "";
        solve(ans, digits, temp, mpp, 0);
        return ans;
    }
};