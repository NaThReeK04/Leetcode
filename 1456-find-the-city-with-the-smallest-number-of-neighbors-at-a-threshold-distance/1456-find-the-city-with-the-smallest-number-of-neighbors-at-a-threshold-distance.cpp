class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            dis[u][v]=w;
            dis[v][u]=w;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dis[i][j]=0;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=distanceThreshold){
                    count++;
                }
            }
            mpp[i]=count;
        }
        int mini=INT_MAX;
        int min_idx=-1;
        for(auto it:mpp){
            if(it.second<=mini){
                mini=it.second;
                min_idx=it.first;
            }
        }
        return min_idx;
      
        
    }
};