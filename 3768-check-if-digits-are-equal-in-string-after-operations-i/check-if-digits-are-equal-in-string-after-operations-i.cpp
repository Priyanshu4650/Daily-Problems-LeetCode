class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2) {
            string curr = "";
            
            for(int i=0;i<s.size() - 1;i++) {
                curr += ((s[i] + s[i + 1]) % 10) + '0';
            }

            s = curr;
        }
        return s[0] == s[1];
    }
};