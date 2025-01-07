class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        set<string> found;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    found.insert(words[i]);
                }
            }
        }

        ans.assign(found.begin(), found.end());
        return ans;
    }
};
