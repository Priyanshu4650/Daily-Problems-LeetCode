class Solution {
    int dijkstra(int n, vector<vector<int>>& adj) {
        int src = 0;
        int dest = n - 1;

        priority_queue<int> pq;
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        pq.push(src);
        
        while(!pq.empty()) {
            int curr = pq.top();
            pq.pop();

            for(int i=0;i<adj[curr].size();i++) {
                
                if(distance[curr] + 1 < distance[adj[curr][i]]) {
                    pq.push(adj[curr][i]);
                    distance[adj[curr][i]] = distance[curr] + 1;
                }
            }
        }

        return distance[dest];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        vector<vector<int>> adj(n);

        for(int i=0;i<n - 1;i++) {
            adj[i].push_back(i + 1);
        } 

        for(auto &query : queries) {
            int u = query[0];
            int v = query[1];

            adj[u].push_back(v);
            result.push_back(dijkstra(n, adj));
        }

        return result;
    }
};