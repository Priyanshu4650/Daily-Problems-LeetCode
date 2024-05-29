class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for(int i=0;i<edges.size();i++) {
            if(!mp[edges[i][0]]) {
                mp[edges[i][0]] = 1;
            }
            else {
                mp[edges[i][0]] += 1;
            }
            if(!mp[edges[i][1]]) {
                mp[edges[i][1]] = 1;
            }
            else {
                mp[edges[i][1]] += 1;
            }
        }
        
        for(auto ele : mp) {
            if(ele.second == edges.size()) return ele.first;
        }

        return -1;
    }
};