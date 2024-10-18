class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        queue<int>q;
        q.push(k);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto it:adj[top]){
                if(dis[top]+it.second<dis[it.first]){
                    dis[it.first]=dis[top]+it.second;
                    q.push(it.first);
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
             if(dis[i]==1e9)return -1;
             maxi=max(maxi,dis[i]);
        }
        return maxi;
    }
};