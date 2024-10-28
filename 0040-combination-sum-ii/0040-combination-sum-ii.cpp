class Solution {
public:
    void helper(vector<int>& help, vector<vector<int>>& ans, vector<int>& candidates, int i, int sum, int n, int target) {
        if (sum == target) {
            ans.push_back(help);
            return;
        }
        if (i == n || sum > target) {
            return;
        }
        help.push_back(candidates[i]);
        helper(help, ans, candidates, i + 1, sum + candidates[i], n, target);
        help.pop_back();

        while (i + 1 < n && candidates[i] == candidates[i + 1]) {
            ++i;
        }

        helper(help, ans, candidates, i + 1, sum, n, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> help;
        helper(help, ans, candidates, 0, 0, candidates.size(), target);
        return ans;
    }
};
