class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<pair<int, int>> s, t;
        s.insert({points[0][0], points[0][1]});
        for(int i=1;i<points.size();i++) {
            t.insert({points[i][0], points[i][1]});
        }

        int res = 0;

        while(t.size() != 0) {
            int mn = INT_MAX;
            pair<int, int> add;

            for(auto f : s) {
                for(auto sec : t) {
                    if(abs(f.first - sec.first) + abs(f.second - sec.second) < mn) {
                        add = sec;
                        mn = abs(f.first - sec.first) + abs(f.second - sec.second);
                    }
                }
            }   
            
            res += mn;

            t.erase(add);
            s.insert(add);
        }

        return res;
    }   
};