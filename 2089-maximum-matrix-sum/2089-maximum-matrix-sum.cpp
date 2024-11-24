class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int value = matrix[i][j];
                totalSum += abs(value);
                minAbsValue = min(minAbsValue, abs(value));
                if (value < 0) {
                    ++negativeCount;
                }
            }
        }
        
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsValue;
        }
        
        return totalSum;
    }
};

