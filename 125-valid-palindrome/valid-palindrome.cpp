class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(int i=0;i<s.size();i++) {
            if(isalpha(s[i])) {
                res += tolower(s[i]);
            }
            else if(isdigit(s[i])) {
                res += s[i];
            }
        }

        cout << res << endl;

        int i = 0;
        int j = res.size() - 1;

        while(i <= j) {
            if(res[i] != res[j]) {
                return false;
            }
            i += 1;
            j -= 1;
        }

        return true;
    }
};