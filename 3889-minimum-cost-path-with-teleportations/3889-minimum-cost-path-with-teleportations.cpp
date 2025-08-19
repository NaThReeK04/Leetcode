#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    struct State {
        int cost, i, j;
        bool operator>(const State& other) const { return cost > other.cost; }
    };

    int minCost(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;
        
        // dp[t][i][j]: min cost to reach (i, j) using exactly t teleports
        std::vector<std::vector<std::vector<int>>> dp(
            k + 1, std::vector<std::vector<int>>(m, std::vector<int>(n, INF)));

        int max_val = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                max_val = std::max(max_val, grid[i][j]);
            }
        }

        // Base case: 0 teleports
        dp[0][0][0] = 0;

        const int di[2] = {1, 0};
        const int dj[2] = {0, 1};

        // Iterate through each layer of teleports
        for (int t = 0; t <= k; ++t) {
            // 1. Teleport Step (if t > 0)
            if (t > 0) {
                std::vector<int> min_cost_by_val(max_val + 1, INF);
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (dp[t - 1][i][j] != INF) {
                            min_cost_by_val[grid[i][j]] = std::min(min_cost_by_val[grid[i][j]], dp[t - 1][i][j]);
                        }
                    }
                }

                // Calculate suffix minimum
                for (int v = max_val - 1; v >= 0; --v) {
                    min_cost_by_val[v] = std::min(min_cost_by_val[v], min_cost_by_val[v + 1]);
                }

                // Initialize current layer's costs from teleports
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        dp[t][i][j] = min_cost_by_val[grid[i][j]];
                    }
                }
            }
            
            // 2. Dijkstra Step (propagate costs via normal moves)
            std::priority_queue<State, std::vector<State>, std::greater<State>> pq;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[t][i][j] != INF) {
                        pq.push({dp[t][i][j], i, j});
                    }
                }
            }

            while (!pq.empty()) {
                auto [cost, i, j] = pq.top();
                pq.pop();

                if (cost > dp[t][i][j]) continue;

                for (int dir = 0; dir < 2; ++dir) {
                    int ni = i + di[dir];
                    int nj = j + dj[dir];

                    if (ni < m && nj < n) {
                        int nc = cost + grid[ni][nj];
                        if (nc < dp[t][ni][nj]) {
                            dp[t][ni][nj] = nc;
                            pq.push({nc, ni, nj});
                        }
                    }
                }
            }
        }

        // Find the minimum cost to reach the destination across all layers
        int result = INF;
        for (int t = 0; t <= k; ++t) {
            result = std::min(result, dp[t][m - 1][n - 1]);
        }

        return (result == INF) ? -1 : result;
    }
};