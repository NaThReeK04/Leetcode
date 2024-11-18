class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> decrypt;

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) { 
                    sum += code[(i + j) % n]; 
                }
                decrypt.push_back(sum);
            }
        } else if (k < 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= -k; j++) { 
                    sum += code[(i - j + n) % n]; 
                }
                decrypt.push_back(sum);
            }
        } else {
            for (int i = 0; i < n; i++) {
                decrypt.push_back(0); 
            }
        }

        return decrypt;
    }
};
