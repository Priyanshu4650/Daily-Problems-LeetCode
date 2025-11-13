class Solution {
public:
    int maxOperations(string s) {
        int countOnes = 0;
        int countZeros = 0;
        int operations = 0;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '1') {
                countOnes += 1;
            }
            else {
                countZeros += 1;
            }
            if(s[i] == '1' && i + 1 < s.size() && s[i + 1] == '0') {
                operations += countOnes;
            }
        }

        return operations;
    }
};