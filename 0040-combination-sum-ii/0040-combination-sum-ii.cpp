class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& comb,
                vector<int>& candidates, int idx, int sum, int target) {
        if (idx == candidates.size()) {
            if (sum == target) {
                ans.push_back(comb);
            }
            return;
        }
        if(sum>target)return;
        comb.push_back(candidates[idx]);
        helper(ans, comb, candidates, idx + 1, sum + candidates[idx], target);
        comb.pop_back();
        while (idx + 1 < candidates.size() &&
               candidates[idx] == candidates[idx + 1]) {
            ++idx;
        }
        helper(ans, comb, candidates, idx + 1, sum, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        helper(ans, comb, candidates, 0, 0, target);
        return ans;
    }
};