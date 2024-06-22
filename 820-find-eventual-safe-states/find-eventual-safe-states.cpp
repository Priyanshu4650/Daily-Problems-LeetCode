class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        if(color[node] != 0) {
            return color[node] == 2;
        }
        
        color[node] = 1; // Mark the node as visiting
        for(int neighbor : graph[node]) {
            if(color[neighbor] == 1 || !dfs(neighbor, graph, color)) {
                return false;
            }
        }
        
        color[node] = 2; // Mark the node as safe
        return true;
    } 
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); 
        vector<int> res;
        
        for(int i = 0; i < n; i++) {
            if(dfs(i, graph, color)) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
