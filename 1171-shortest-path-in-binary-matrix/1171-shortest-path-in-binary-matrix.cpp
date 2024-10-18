class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==0&&n==1)return 1;
        if(grid[0][0]==1||grid[n-1][n-1]==1)return -1;
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(n,0));
        int delrow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int,int>>q;
        q.push({0,0});
        dis[0][0]=1;
        vis[0][0]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=node.first+delrow[i];
                int ncol=node.second+delcol[i];
                if(nrow>=0
                &&nrow<n
                &&ncol>=0
                &&ncol<n
                &&!vis[nrow][ncol]
                &&grid[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    if(dis[node.first][node.second]+1<dis[nrow][ncol]){
                        dis[nrow][ncol]=dis[node.first][node.second]+1;
                        q.push({nrow,ncol});
                        if(nrow==n-1&&ncol==n-1) return dis[n-1][n-1];
                    }

                }
            }
        }

        return -1;

    }
};