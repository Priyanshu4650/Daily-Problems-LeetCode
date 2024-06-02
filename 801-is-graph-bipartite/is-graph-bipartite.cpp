class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0); // Color of each vertex: 0 (unvisited), 1 and -1 (two different colors)
        
        for (int i = 0; i < graph.size(); ++i) {
            if (color[i] == 0) { // If the current vertex is unvisited
                if (!dfs(graph, color, i, 1)) // Check if the graph is bipartite starting from this vertex
                    return false;
            }
        }
        return true; // Graph is bipartite
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int col) {
        color[node] = col; // Color the current node
        
        for (int neighbor : graph[node]) {
            if (color[neighbor] == col) // If the neighbor has the same color as the current node, the graph is not bipartite
                return false;
            if (color[neighbor] == 0 && !dfs(graph, color, neighbor, -col)) // If the neighbor is unvisited, continue DFS
                return false;
        }
        return true; // DFS traversal completed, graph is bipartite
    }
};
