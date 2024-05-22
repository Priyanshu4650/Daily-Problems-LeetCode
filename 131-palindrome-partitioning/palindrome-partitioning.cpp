class Solution {
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;

        partitionHelper(s, 0, temp, res);

        return res;
    }

    void partitionHelper(string& s, int start, vector<string>& temp, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i - start + 1);
            if (isPalindrome(sub)) {
                temp.push_back(sub);
                partitionHelper(s, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
};
