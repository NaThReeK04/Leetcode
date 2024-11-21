class Solution {
public:
    void dfs(int r,int c,string dir,vector<vector<int>>&ground,vector<vector<int>>&vis){
        int n = vis.size();
        int m = vis[0].size();
        if(r<0 || c<0 || r>=n || c>=m) return;
        if(ground[r][c]==1||ground[r][c]==-1)return;
        else vis[r][c]=1;
        if(dir == "r"){
            dfs(r, c+1, "r", ground, vis);
        }
        if(dir == "l"){
            dfs(r, c-1, "l", ground, vis);
        }
        if(dir == "u"){
            dfs(r-1, c, "u", ground, vis);
        }
        if(dir == "d"){
            dfs(r+1, c, "d", ground, vis);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>ground(m,vector<int>(n,0));
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            int first=guards[i][0];
            int second=guards[i][1];
            ground[first][second]=1;
            vis[first][second]=1;
        }
        for(int i=0;i<walls.size();i++){
            int first=walls[i][0];
            int second=walls[i][1];
            ground[first][second]=-1;
            vis[first][second]=1;
        }
        for(int i=0;i<guards.size();i++){
            int r=guards[i][0];
            int c=guards[i][1];
            dfs(r,c+1,"r",ground,vis);
            dfs(r+1,c,"d",ground,vis);
            dfs(r,c-1,"l",ground,vis);
            dfs(r-1,c,"u",ground,vis);
        }
        int count=0;
        for(int i=0;i<vis.size();i++){
            for(int j=0;j<vis[0].size();j++){
                if(vis[i][j]==0)count++;
            }
        }
        return count;
    }
};