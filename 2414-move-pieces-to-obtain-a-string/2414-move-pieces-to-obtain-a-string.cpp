class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;

        while (i < n && j < n) {
            
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            if (i == n && j == n) return true;

            if (i == n || j == n) return false;

            if (start[i] != target[j]) return false;

            if (start[i] == 'L' && i < j) return false;

            if (start[i] == 'R' && i > j) return false;

            i++;
            j++;
        }

        while (i < n) {
            if (start[i] != '_') return false;
            i++;
        }
        while (j < n) {
            if (target[j] != '_') return false;
            j++;
        }

        return true;
    }
};

