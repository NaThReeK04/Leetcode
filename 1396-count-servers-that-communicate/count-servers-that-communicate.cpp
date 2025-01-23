class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid,int m,int n,int dir){
        if(i<0||i>=n||j<0||j>=m)return 0;
        if(grid[i][j]==1)return 1;
        if(dir==1)return dfs(i,j+1,grid,m,n,1);
        if(dir==2) return dfs(i,j-1,grid,m,n,2);
        if(dir==3)return dfs(i+1,j,grid,m,n,3);
        if(dir==4) return dfs(i-1,j,grid,m,n,4);
        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int ans1=dfs(i,j+1,grid,m,n,1);
                    int ans2=dfs(i,j-1,grid,m,n,2);
                    int ans3=dfs(i+1,j,grid,m,n,3);
                    int ans4=dfs(i-1,j,grid,m,n,4);
                    if(ans1||ans2||ans3||ans4){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};