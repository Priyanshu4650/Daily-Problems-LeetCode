class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++) {
            mp[s[i]] += 1;
        }
        int res = 0;
        int oddcount = 0;
        for(auto it : mp) {
            if(it.second % 2 == 0) {
                res += it.second;
            }
            else {
                res += (it.second / 2)*2;
                oddcount = 1;
            }
        }
        return res + oddcount;
    }
};