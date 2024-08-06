class Solution {
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i ++;
            j -= 1;
        }

        return true;
    }
    void backtrack(string s, int start, vector<string>& temp, vector<vector<string>>& result) {
        if(start == s.size()) {
            result.push_back(temp);
            return;
        }

        for(int i=start;i<s.size();i++) {
            string sub = s.substr(start, i - start + 1);
            if(isPalindrome(sub)) {
                temp.push_back(sub);
                backtrack(s, i + 1, temp, result);
                temp.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;

        backtrack(s, 0, temp, result);

        return result;
    }
};