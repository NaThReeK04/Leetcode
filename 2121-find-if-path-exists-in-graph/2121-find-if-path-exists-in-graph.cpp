class Solution {
public:
    void dfs(bool &ye,vector<int>&vis,vector<int>adj[],int source,int destination){
        if(source==destination)ye=true;
        vis[source]=1;
        for(auto it:adj[source]){
            if(!vis[it]){
                dfs(ye,vis,adj,it,destination);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        bool ye=false;
        dfs(ye,vis,adj,source,destination);
        if(ye){
            return true;
        }
        return false;
    }
};