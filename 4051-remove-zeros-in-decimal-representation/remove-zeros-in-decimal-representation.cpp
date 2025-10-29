class Solution {
public:
    long long removeZeros(long long n) {
        long long res = 0;
        string num = to_string(n);
        
        for(int i=0;i<num.size();i++) {
            if(num[i] == '0')
                continue;
            else {
                res = res * 10 + num[i] - '0';
            }
        }

        return res;
    }
};