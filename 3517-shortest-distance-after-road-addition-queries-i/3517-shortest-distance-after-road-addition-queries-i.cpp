class Solution
{
    public:
        vector<int> shortestDistanceAfterQueries(int n, vector<vector < int>> &queries)
        {
            vector<vector < int>> adj(n);
            vector<int> answers; 
            int m = queries.size();
            for (int i = 0; i < n - 1; i++)
            {
                adj[i].push_back( i + 1 );
            }
            
            
            for (int i = 0; i < m; i++)
            {
                adj[queries[i][0]].push_back( queries[i][1] );
                queue<int> q;
                q.push(0);
                vector<int> path(n , 1e9);
                path[0] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (auto it: adj[node])
                    {
                        if (path[node] + 1 < path[it])
                        {
                            path[it] = path[node] + 1;
                            q.push(it);
                        }
                    }
                }
                answers.push_back(path[n - 1]==1e9?-1:path[n-1]);
            }
            return answers;
        }
};