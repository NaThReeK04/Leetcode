class Solution {
public:
    void dfs(vector<vector<int>>& stones, vector<int>& vis, int n, int &result, int index) {
        vis[index] = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])) {
                result++;  
                dfs(stones, vis, n, result, i);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, 0); 
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) { 
                dfs(stones, vis, n, result, i);
            }
        }
        return result; 
    }
};
