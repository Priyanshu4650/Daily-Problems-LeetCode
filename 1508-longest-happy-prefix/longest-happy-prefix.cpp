class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        if (n == 0) return "";

        // Create an lps array to store lengths of longest proper prefix which is also a suffix
        vector<int> lpsArray(n, 0);
        int len = 0; // length of the previous longest prefix which is also suffix

        // lpsArray[0] is always 0 since a single character cannot be a proper prefix and suffix
        int i = 1;

        // Start calculating lps values for the rest of the characters in the string
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lpsArray[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lpsArray[len - 1];
                } else {
                    lpsArray[i] = 0;
                    i++;
                }
            }
        }

        // Length of longest proper prefix which is also suffix will be lpsArray[n-1]
        return s.substr(0, lpsArray[n - 1]);
    }
};