class Solution {
    // Memoization table to store results of subproblems
    unordered_map<string, unordered_map<string, int>> memo;

    // Helper function to check if a string is a palindrome, with caching
    bool isPalindrome(const string& s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) 
                return false;
            i++;
            j--;
        }

        return true;        
    }

    // Recursive backtrack function to find the maximum product
    int backtrack(const string& s, int i, string a, string b) {
        if (i >= s.size()) {
            return (isPalindrome(a) && isPalindrome(b)) ? a.size() * b.size() : 0;
        }

        // Check memoization table to avoid recomputation
        if (memo[a][b] != 0) return memo[a][b];

        // Considering three scenarios:
        // 1. Add the current character to string a
        int best = backtrack(s, i + 1, a + s[i], b);
        
        // 2. Add the current character to string b
        best = max(best, backtrack(s, i + 1, a, b + s[i]));

        // 3. Skip the current character
        best = max(best, backtrack(s, i + 1, a, b));

        // Store the result in the memoization table
        return memo[a][b] = best;
    }

public:
    int maxProduct(string s) {
        memo.clear();
        return backtrack(s, 0, "", "");
    }
};
