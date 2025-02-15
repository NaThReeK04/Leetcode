class Solution {
public:
    bool isPossible(int i, string t, string s, int n, int target) {
        if (i == n) {
            int sum1 = 0;
            string temp = "";
            for (int j = 0; j < t.length(); j++) {
                if (isdigit(t[j])) {
                    temp += t[j];
                } else if (t[j] == '+') {
                    sum1 += stoi(temp);
                    temp.clear();
                }
            }
            if (!temp.empty()) {
                sum1 += stoi(temp);
            }
            return sum1 == target;
        }

        bool ans1 = isPossible(i + 1, t + string(1, s[i]) + "+", s, n, target);
        bool ans2 = isPossible(i + 1, t + string(1, s[i]), s, n, target);
        return ans1 || ans2;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            int length = s.length();
            if (isPossible(0, "", s, length, i)) {
                sum += (i * i);
            }
        }
        return sum;
    }
};
