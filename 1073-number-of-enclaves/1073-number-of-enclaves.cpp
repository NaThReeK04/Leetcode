class Solution {
public:
   void dfs(int row, int col, vector<vector < int>> &vis, vector< vector<int>> &grid, int delrow[], int delcol[])
        {
            int n = grid.size();
            int m = grid[0].size();
            vis[row][col] = 1;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    dfs(nrow, ncol, vis, grid, delrow, delcol);
                }
            }
        }
    int numEnclaves(vector<vector<int>>& grid) {
        int delrow[] = { 0,1,0,-1};
        int delcol[] = { 1,0,-1,0};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector < int>> vis(n, vector<int> (m, 0));
       	//traverse first and last row
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && grid[0][j] == 1)
            {
                dfs(0, j, vis, grid, delrow, delcol);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
            {
                dfs(n - 1, j, vis, grid, delrow, delcol);
            }
        }
       	//traverse first and last column
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, vis, grid, delrow, delcol);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            {
                dfs(i, m - 1, vis, grid, delrow, delcol);
            }
        }
        int count=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};