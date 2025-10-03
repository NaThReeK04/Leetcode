class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        int maxi = 0;
        string temp;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    int len = dp[i][j];

                    // index in t corresponds to reversed index in s
                    int origStart = i - len;
                    int revStart  = n - j;
                    if (origStart == revStart) { // ✅ ensures palindrome
                        if (len > maxi) {
                            maxi = len;
                            temp = s.substr(origStart, len);
                        }
                    }
                }
            }
        }
        return temp;
    }
};
