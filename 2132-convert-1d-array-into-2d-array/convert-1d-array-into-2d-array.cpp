class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        if(original.size() != m * n) {
            return {};
        }

        for(int i=0;i<original.size();i++) {
            mat[i/n][i%n] = original[i];
        }

        return mat;
    }
};