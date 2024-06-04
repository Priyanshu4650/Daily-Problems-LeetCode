class Solution {
public:
    int minimumChairs(string s) {
        int res = 0;
        int take = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == 'E') {
                take += 1;
                res = max(res, take);
            }
            else {
                take -= 1;
            }
        }
        return res;
    }
};