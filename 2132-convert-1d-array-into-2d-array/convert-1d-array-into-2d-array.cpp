class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {}; // Return an empty 2D array if dimensions are incompatible
        }

        std::vector<std::vector<int>> mat(m, std::vector<int>(n, 0));

        for (int i = 0; i < original.size(); ++i) {
            int row = i / n; // Calculate row index
            int col = i % n; // Calculate column index
            mat[row][col] = original[i];
        }

        return mat;
    }
};