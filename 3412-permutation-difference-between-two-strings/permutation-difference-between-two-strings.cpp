class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int, int> mp;
        for(int i=0;i<s.size();i++) {
            mp[s[i]] = i;
        }
        int res = 0;
        for(int i=0;i<t.size();i++) {
            res += abs(i - mp[t[i]]);
        }
        return res;
    }
};