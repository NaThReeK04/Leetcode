class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s1.length(); i++) {
            mpp[s1[i]]++;
        }
        int i = 0, j = 0;
        while (i <= j && j < s2.length()) {
            if (mpp.find(s2[j]) != mpp.end()) {
                while (mpp.find(s2[j]) != mpp.end()) {
                    mpp[s2[j]]--;
                    if (mpp[s2[j]] == 0) {
                        mpp.erase(s2[j]);
                    }
                    j++;
                }
                if (mpp.size() == 0)
                    return true;
                while (mpp.find(s2[j]) == mpp.end() && i != j) {
                    mpp[s2[i]]++;
                    i++;
                }
            } else {
                i++;
                j++;
            }
        }
        return false;
    }
};