class Solution {
    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;  // Skip the edge to the parent node
            if (visited[neighbor]) {
                return {node, neighbor};  // Found a cycle
            }
            auto result = dfs(neighbor, node, adj, visited);
            if (result[0] != -1) return result;  // Cycle found in deeper recursion
        }
        return {-1, -1};  // No cycle found
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, false);
        
        for (auto& edge : edges) {
            fill(visited.begin(), visited.end(), false);
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            if (dfs(edge[0], -1, adj, visited)[0] != -1) {
                return edge;  
            }
        }
        return {};
    }
};