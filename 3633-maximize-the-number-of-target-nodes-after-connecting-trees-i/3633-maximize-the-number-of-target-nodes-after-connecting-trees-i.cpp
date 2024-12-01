class Solution {
public:
    int bfs(int idx, int n, vector<vector<int>>& adj, int limit) {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(idx);
        vis[idx] = 1;
        int count = 0, nodes = 0;

        while (!q.empty() && count <= limit) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();
                nodes++;
                for (auto& neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
            count++;
        }
        return nodes;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();

        vector<vector<int>> adj1(n + 1), adj2(m + 1);
        for (const auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        if (k == 0) {
            vector<int> result(n + 1, 1);
            return result;
        }

        vector<int> dist1(n + 1), dist2(m + 1);
        for (int i = 0; i <= n; ++i) {
            dist1[i] = bfs(i, n, adj1, k);
        }
        for (int j = 0; j <= m; ++j) {
            dist2[j] = bfs(j, m, adj2, k - 1);
            if (dist2[j] == 0) dist2[j] = 1; 
        }

        int maxi = *max_element(dist2.begin(), dist2.end());
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; ++i) {
            ans[i] = dist1[i] + maxi;
        }

        return ans;
    }
};
