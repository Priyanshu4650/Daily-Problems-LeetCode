class Solution {
    void backtrack(int n, vector<string>& res, int open, int closed, string curr) {
        if(open < closed) {
            return;
        } 
        if(open == closed && open == n) {
            res.push_back(curr);
        }
        if(curr.size() > 2 * n) {
            return;
        }
        if(open > closed) {
            backtrack(n, res, open, closed + 1, curr + ')');
        }
        backtrack(n, res, open + 1, closed, curr + '(');
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";

        backtrack(n, result, 0, 0, curr);

        return result;
    }
};