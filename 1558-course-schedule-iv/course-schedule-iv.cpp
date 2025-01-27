class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int search) {
    vis[node] = 1;
    if (node == search) {
        return true;
    }
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, adj, vis, search)) {
                return true;
            }
        }
    }
    return false;
}

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses,vector<int>());
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        int n=queries.size();
        vector<bool>ans(n,false);
        for(int i=0;i<n;i++){
            int start=queries[i][0];
            int search=queries[i][1];
            vector<int>vis(numCourses,0);
            vis[start]=1;
            ans[i]=dfs(start,adj,vis,search);
        }
        return ans;
    }
};