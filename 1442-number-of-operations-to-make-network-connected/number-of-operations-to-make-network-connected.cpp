class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for(int i = 0; i < adj[node].size(); i++) {
            if(!visited[adj[node][i]]) {
                dfs(adj[node][i], adj, visited);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<bool> visited(n, false);
        vector<vector<int>> adj(n); // Initialize adjacency list with n nodes
        
        for(const auto& con : connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }

        // To make all nodes connected, we need count-1 cables
        return count - 1;
    }
};