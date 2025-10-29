class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        if(sum > 9 * num)   
            return res;
        
        while(num > 0) {
            if(sum >= 9) {
                res += to_string(9);
                sum -= 9;
            }
            else {
                res += to_string(sum);
                sum = 0;
            }
            num -= 1;
        }

        return res;
    }
};