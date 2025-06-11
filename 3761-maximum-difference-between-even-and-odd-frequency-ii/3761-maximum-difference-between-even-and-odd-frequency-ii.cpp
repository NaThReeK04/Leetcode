class Solution {
private:
    vector<vector<int>> freq;
    // even or odd
    int parity(int num) {
        return num & 1;
    }

    int max_subarray_sum(int a, int b, string& s, int k) {
        int n = s.size();
        int l = 0, r = k - 1;
        
        int r_freq_a = 0, r_freq_b = 0;
        int l_freq_a = 0, l_freq_b = 0;

        int sum = INT_MIN;
        // mat denotes second part, we have to minimize it
        const int INF = 1e8;
        int mat[2][2] = {{INF, INF}, {INF, INF}};

        while (r < n) {
            // update right-side prefix counts
            r_freq_a = freq[a][r+1];
            r_freq_b = freq[b][r+1];

            // can we move window from left
            while (r - l + 1 >= k && (r_freq_b - l_freq_b) >= 2) {
                // update current minimum
                mat[parity(l_freq_a)][parity(l_freq_b)] =
                    min(mat[parity(l_freq_a)][parity(l_freq_b)], l_freq_a - l_freq_b);

                // move towards next window
                l_freq_a = freq[a][l+1];
                l_freq_b = freq[b][l+1];
                l++;
            }

            int calc = (r_freq_a - r_freq_b) - mat[parity(r_freq_a) ^ 1][parity(r_freq_b)];
            sum = max(calc, sum);

            r++;
        }

        return sum;  
    }

public:
    int maxDifference(string s, int k) {
        int n = s.size();
        // resizing the vector to n+1 length and 5 size i.e. 0,1,2,3,4
        freq = vector<vector<int>>(5, vector<int> (n+1 ,0));

        for (int i = 0; i < n; i++) {
            /// move all frequencies to current index
            for(int j=0;j<=4;j++){
                freq[j][i+1] = freq[j][i];
            }

            int conv = s[i] - '0';
            freq[conv][i+1]++;
        }

        int diff = INT_MIN;

        // going from all possible pairs
        for (int i = 0; i <= 4; i++) {
            if(freq[i][n] == 0){continue;}

            for (int j = 0; j <= 4; j++) {
                if (i == j or freq[j][n] == 0){continue;}

                int calc = max_subarray_sum(i, j, s, k);
                diff = max(diff, calc);
            }
        }

        return diff;
    }
};