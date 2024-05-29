class Solution {
public:
    void dfs(vector<int> adj[], vector<bool> &visited,int source, int &nodeCount, int &edgeCount){
        visited[source]=true;
        nodeCount+=1;
        edgeCount+=adj[source].size();

        for(auto i:adj[source]){
            if(visited[i]==0){
                dfs(adj,visited,i,nodeCount,edgeCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> visited (n,0);

        for(auto i : edges){
            int f1 = i[0];
            int s1 = i[1];
            adj[f1].push_back(s1);
            adj[s1].push_back(f1);
        }

        int count=0;
        for(int i=0;i<n;i++){
            //for connected graph we need to keep count of nodes and edges
            int nodeCount=0, edgeCount=0;
            if(visited[i]==0){
                dfs(adj,visited,i,nodeCount,edgeCount);
                
                //formula to check if nodes and edges form a connected graph
                if(nodeCount*(nodeCount-1)==edgeCount){
                    count++;
                }
            }
        }

        return count;
    }
};