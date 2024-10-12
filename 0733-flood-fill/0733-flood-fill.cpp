class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int co=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int si=q.size();
            while(si--){
                auto [x,y]=q.front();
                if(image[x][y]==co){
                    image[x][y]=color;
                }
                vis[x][y]=1;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int dx = dir[k][0];
                    int dy = dir[k][1];
                    
                    int i = x + dx;
                    int j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && image[i][j] == co) {
                        image[i][j] = color;
                        q.push({i, j});
                    }
                }
            }

        }
        return image;


    }
};