class Solution {
public:
    void backtrack(set<string>& s, string temp, vector<int>& freq) {
        if (!temp.empty()) {
            s.insert(temp);
        }
        for (int j = 0; j < 26; j++) {
            if (freq[j] > 0) {
                freq[j]--;
                backtrack(s, temp + char('A' + j), freq);
                freq[j]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char ch : tiles) {
            freq[ch - 'A']++;
        }
        set<string> s;
        backtrack(s, "", freq);
        return s.size();
    }
};
