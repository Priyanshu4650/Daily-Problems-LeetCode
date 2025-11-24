class Solution {
public:
    int totalWaviness(int num1, int num2) {
        long long sum = 0;

        for(int i = num1; i <= num2; i++) {
            int temp = i;

            if(temp < 100) continue; // fewer than 3 digits -> cannot be wavy

            int prev = temp % 10;  // least significant digit
            temp /= 10;
            int curr = temp % 10;
            temp /= 10;

            while(temp > 0) {
                int next = temp % 10;

                if((curr > prev && curr > next) || (curr < prev && curr < next)) {
                    sum++;
                }

                prev = curr;
                curr = next;
                temp /= 10;
            }
        }

        return sum;
    }
};
