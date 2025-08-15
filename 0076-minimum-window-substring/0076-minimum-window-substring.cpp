class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> mpp;
        for (char c : t) mpp[c]++;

        int i = 0, j = 0;
        int n = s.size();
        int minsize = INT_MAX;
        int start = 0;
        int need = t.size(); // total chars needed

        while (j < n) {
            // expand window
            if (mpp.find(s[j]) != mpp.end()) {
                if (mpp[s[j]] > 0) need--;
                mpp[s[j]]--;
            }
            j++;

            // shrink window when all chars found
            while (need == 0) {
                if (j - i < minsize) {
                    minsize = j - i;
                    start = i;
                }

                if (mpp.find(s[i]) != mpp.end()) {
                    mpp[s[i]]++;
                    if (mpp[s[i]] > 0) need++;
                }
                i++;
            }
        }

        return minsize == INT_MAX ? "" : s.substr(start, minsize);
    }
};
