class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        if (vis[node] == 1) { // Cycle detected
            return true; // Node is being visited, indicates a cycle
        }
        if (vis[node] == 2) { // Node has already been processed
            return false; // No need to process it again
        }
        
        // Mark the node as being visited
        vis[node] = 1; 
        
        // Perform DFS on all adjacent nodes
        for (auto it : adj[node]) {
            if (dfs(it, vis, adj, st)) { // If cycle detected in the recursive call
                return true; 
            }
        }
        
        // Mark the node as fully processed
        vis[node] = 2; 
        st.push(node); // Push the node onto the stack after all its adjacent nodes are processed
        return false; // No cycle detected
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses]; // Adjacency list representation
        int n = prerequisites.size();

        // Building the adjacency list
        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(numCourses, 0); // Visited array to keep track of node states
        stack<int> st;

        // Perform DFS for each unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) { // Not visited
                if (dfs(i, vis, adj, st)) { // If cycle detected
                    return {}; // Return an empty vector if a cycle is detected
                }
            }
        }

        // Pop elements from the stack to get the topological order
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans; // Return the topological order if no cycle is detected
    }
};
