class Solution {
    void dfs(vector<vector<int>>& graph, set<vector<int>>& s, int n, vector<int>& temp, vector<bool>& visited, int v) {
        temp.push_back(v);
        visited[v] = true;
        if(v == n - 1) {
            s.insert(temp);
        }
        for(int i=0;i<graph[v].size();i++) {
            if(visited[graph[v][i]] == false) {
                dfs(graph, s, n, temp, visited, graph[v][i]);
                temp.pop_back();
                visited[graph[v][i]] = false;
            }
        }
        // return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        vector<bool> visited(n, false);
        set<vector<int>> s;
        vector<int> temp;

        dfs(graph, s, n, temp, visited, 0);

        for(auto it : s) {
            res.push_back(it);
        }
        
        return res;
    }
};