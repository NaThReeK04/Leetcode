class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        for(auto a:adj[node]){
            if(!vis[a]){
                vis[a]=1;
                dfs(a,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int>vis(n+1,0);
        int count=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};