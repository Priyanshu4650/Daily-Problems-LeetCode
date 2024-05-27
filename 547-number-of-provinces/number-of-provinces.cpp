class Solution {
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int v) {
        visited[v] = true;  // Mark the current node as visited
        for(int i = 0; i < isConnected.size(); i++) {
            if(isConnected[v][i] == 1 && !visited[i]) {  // Visit connected nodes
                dfs(isConnected, visited, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);  // Visited array for n nodes
        int count = 0;

        for(int i = 0; i < n; i++) {  // Iterate through all nodes
            if(!visited[i]) {  // If the node has not been visited
                dfs(isConnected, visited, i);  // Perform DFS
                count++;  // Increment the count of connected components
            }
        }

        return count;  // Return the number of connected components
    }
};
