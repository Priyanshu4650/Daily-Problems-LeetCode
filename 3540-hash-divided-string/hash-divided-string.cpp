class Solution {
public:
    string stringHash(string s, int k) {
        string res = "";
        for(int i=0;i<s.size();i=i+k) {

            int sum = 0;
            for(int j=i;j<i+k;j++) {
                sum = (sum + s[j] - 'a') % 26;
            }            

            res += 'a' + sum;
        }
        return res;
    }
};