class Solution {
    int log_a_to_base_b(int a, int b)
    {
        return log2(a) / log2(b);
    }
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) 
            return false;
        
        bool isNeg = n < 0;

        int x = log_a_to_base_b(n, 3);

        if(!isNeg) {
            if(pow(3, x) == n) 
                return true;
            return false;
        } 
        return false;
    }
};