class Solution {
    void backtrack(set<vector<int>>& s, int n, int k, int ind, vector<int>& curr) {
        if (k == 0) {
            s.insert(curr);
            return;
        }

        if (ind > n) {
            return;
        }

        for (int i = ind; i <= n; ++i) {
            curr.push_back(i);
            backtrack(s, n, k - 1, i + 1, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        set<vector<int>> s;
        vector<int> curr;
        backtrack(s, n, k, 1, curr);

        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};