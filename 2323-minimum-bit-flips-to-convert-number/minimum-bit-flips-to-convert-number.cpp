class Solution {
public:
    int minBitFlips(int start, int goal) {
        int countBits = 0;

        while(start && goal) {
            countBits += (start % 2) != (goal % 2);
            start /= 2;
            goal /= 2;
        }

        while(start) {
            countBits += (start % 2) != 0;
            start /= 2;
        }

        while(goal) {
            countBits += (goal % 2) != 0;
            goal /= 2;
        }

        return countBits;
    }
};