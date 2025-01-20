class Solution
{
    public:
        int firstCompleteIndex(vector<int> &arr, vector<vector< int>> &mat)
        {
            unordered_map<int, pair<int, int>> mpp;
            int m = mat.size();
            int n = mat[0].size();
            int k = arr.size();
            vector<int>CountRow(m,0);
            vector<int>CountCol(n,0);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mpp[mat[i][j]] = {i,j};
                }
            }
            int idx;
            for (int i = 0; i < k; i++)
            {
                int r = mpp[arr[i]].first;
                int c = mpp[arr[i]].second;
                CountRow[r]++;
                CountCol[c]++;
                if (CountRow[r] == n || CountCol[c] == m)
                {
                    idx = i;
                    break;
                }
            }
            return idx;
        }
};