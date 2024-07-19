class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;
        int shift = floor(log2(n));
        int x = (1 << (shift + 1)) - 1;

        return x - minimumOneBitOperations(n^(1 << shift));
    }
};