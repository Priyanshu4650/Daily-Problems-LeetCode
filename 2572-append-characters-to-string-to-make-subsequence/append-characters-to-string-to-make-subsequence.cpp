class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;

        int n = s.size();
        int m = t.size();

        while(i < n && j < m) {
            if(s[i] == t[j]) {
                i += 1;
                j += 1;
            }
            else {
                i += 1;
            }
        }

        return m - j;
    }
};