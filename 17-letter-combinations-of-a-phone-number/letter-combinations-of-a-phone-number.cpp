class Solution {
    vector<string> chars= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(string digits, vector<string>& result, string curr, int ind) {
        if(ind == digits.size()) {
            result.push_back(curr);
            return;
        }
        
        for(int j=0;j<chars[digits[ind] - '0'].size();j++) {
            backtrack(digits, result, curr + chars[digits[ind] - '0'][j], ind + 1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits == "") {
            return result;
        }
        string curr = ""; 
        backtrack(digits, result, curr, 0);

        return result;
    }
};