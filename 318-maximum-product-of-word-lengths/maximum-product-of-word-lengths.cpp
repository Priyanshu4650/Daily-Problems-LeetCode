class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n == 0) return 0;

        vector<int> bitmask(n, 0);
        vector<int> length(n, 0);

        // Compute the bitmask for each word
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (char c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            bitmask[i] = mask;
            length[i] = words[i].size();
        }

        int result = 0;

        // Compare each pair of words
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((bitmask[i] & bitmask[j]) == 0) { // No common characters
                    result = max(result, length[i] * length[j]);
                }
            }
        }

        return result;
    }
};
