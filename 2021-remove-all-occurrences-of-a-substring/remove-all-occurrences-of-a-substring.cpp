class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.length();
        int i = 0;
        
        while (i <= (int)s.length() - m) { 
            string ss = s.substr(i, m);
            if (ss == part) {
                s.erase(i, m);
                i = max(0, i - m);
            } else {
                i++;
            }
        }
        
        return s;
    }
};
