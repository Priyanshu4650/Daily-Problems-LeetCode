class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int n = rooms.size();
        visited[0] = true;

        queue<int> q;
        for(int i=0;i<rooms[0].size();i++)
            q.push(rooms[0][i]);

        while(!q.empty()) {
            int curr = q.front();
            visited[curr] = true;

            for(int i=0;i<rooms[curr].size();i++) {
                if(visited[rooms[curr][i]] == false) {
                    q.push(rooms[curr][i]);
                }
            }
            q.pop();
            // cout << q.size() << " " << q.front() << " " << curr << endl;
        }

        // cout << "VISITED" << endl;
        // for(int i=0;i<n;i++) {
        //     cout << visited[i] << " " << i << endl;
        // }

        for(int i=0;i<n;i++) {
            // cout << visited[i] << " " << i << endl;
            if(visited[i] == false) {
                return false;
            }
        }

        return true;
    }
};