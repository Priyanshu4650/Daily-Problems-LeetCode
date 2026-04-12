class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res;

        for(auto row: matrix) {
            res.push_back(count(row.begin(), row.end(), 1));
        }   
        
        return res;
    }
};