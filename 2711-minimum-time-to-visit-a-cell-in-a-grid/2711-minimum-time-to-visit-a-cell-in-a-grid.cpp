class Solution {
public:
    #define P pair<int,pair<int,int>>
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto parent = pq.top();
            pq.pop();
            int time = parent.first;
            int row = parent.second.first;
            int col = parent.second.second;

            if (row == m - 1 && col == n - 1) return time;
            if (vis[row][col]) continue;

            vis[row][col] = true;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n || vis[nrow][ncol]) continue;

                int wait = (grid[nrow][ncol] - time) % 2 == 0;
                pq.push({max(grid[nrow][ncol] + wait, time + 1), {nrow, ncol}});
            }
        }
        return -1; 
    }
};
