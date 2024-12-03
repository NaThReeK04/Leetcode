class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        int j = 0;
        string temp = "";
        for (int i = 0; i < n; ++i) {
            if (j < m && i == spaces[j]) {
                temp += ' ';
                ++j;
            }
            temp += s[i];
        }
        return temp;
    }
};
