class Solution {
    void helper(vector<bool>& visited, int n, int p, int& count) {
        if (p > n) {
            count += 1;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (p % i == 0 || i % p == 0)) {
                visited[i] = true;
                helper(visited, n, p + 1, count);
                visited[i] = false;
            }
        }
    }
    
public:
    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        int count = 0;
        helper(visited, n, 1, count);
        return count;
    }
};