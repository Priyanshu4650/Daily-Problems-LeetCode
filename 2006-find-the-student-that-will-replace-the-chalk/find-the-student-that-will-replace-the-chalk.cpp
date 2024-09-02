class Solution {
public:
    int chalkReplacer(std::vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;

        // Calculate the total sum of the chalk array
        for (int c : chalk) {
            sum += c;
        }

        // Reduce k to within the range of one full cycle of chalk
        k %= sum;

        // Find the index of the student who will be the first to run out of chalk
        for (int i = 0; i < n; ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        // Should never reach here since k should be less than sum
        return -1;
    }
};