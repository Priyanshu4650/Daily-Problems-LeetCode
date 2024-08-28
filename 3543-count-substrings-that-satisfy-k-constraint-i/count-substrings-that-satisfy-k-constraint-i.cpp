class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int cnt = 0;

        // Consider all possible substrings
        for (int len = 1; len <= n; len++) {
            int one = 0, zero = 0;

            // Sliding window over the string
            for (int i = 0; i < len; i++) {
                if (s[i] == '1') one++;
                else if (s[i] == '0') zero++;
            }

            if (one <= k || zero <= k) cnt++;

            for (int i = len; i < n; i++) {
                if (s[i - len] == '1') one--;
                else if (s[i - len] == '0') zero--;

                if (s[i] == '1') one++;
                else if (s[i] == '0') zero++;

                if (one <= k || zero <= k) cnt++;
            }
        }

        return cnt;
    }
};
