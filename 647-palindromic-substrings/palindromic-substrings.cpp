class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {

            // checking for odd length palindromes
            int l = i;
            int r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {
                result += 1;
                l -= 1;
                r += 1;
            }

            // checking for even length palindromes
            l = i;
            r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                result += 1;
                l -= 1;
                r += 1;
            }
        }

        return result;
    }
};
