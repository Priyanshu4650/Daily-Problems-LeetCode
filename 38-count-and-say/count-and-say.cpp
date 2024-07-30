class Solution {
    string helper(string res) {
        int cnt = 1;
        string out = "";

        for(int i=0;i<res.size();i++) {
            if(i + 1 < res.size() && res[i] == res[i + 1]) {
                cnt += 1;
            }
            else {
                out += to_string(cnt) + res[i];
                cnt = 1;
            }
        }

        return out;
    }
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }

        string res = "1";
        for(int i=1;i<n;i++) {
            res = helper(res);
        }

        return res;
    }
};