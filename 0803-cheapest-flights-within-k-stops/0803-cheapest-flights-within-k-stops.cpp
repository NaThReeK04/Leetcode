class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        pq.push({0,{src, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int stop=it.first;
            int node = it.second.first;
            int cost = it.second.second;

      
            if (stop > k) continue;

          
            for (auto neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int price = neighbor.second;
                int newCost =cost + price;

           
                if (newCost < dis[nextNode]&&stop<=k) {
                    dis[nextNode] = newCost;
                    pq.push({stop+1,{nextNode,newCost}});
                }
            }
        }

   
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};
