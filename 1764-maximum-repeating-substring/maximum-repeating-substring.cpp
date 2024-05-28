class Solution {
    int getMax(string sequence, int ind, string word) {
        int i = ind;
        int count = 0;

        while (i + word.size() <= sequence.size()) { // Changed '<' to '<='
            cout << sequence.substr(i, word.size()) << " " << i << " " << count << endl;
            if (sequence.substr(i, word.size()) == word) {
                count += 1;
                i += word.size();
            } else {
                return count;
            }
        }

        return count;
    }
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        for (int i = 0; i < sequence.size(); i++) {
            if (sequence[i] == word[0]) {
                res = max(res, getMax(sequence, i, word));
            }
        }
        return res;
    }
};