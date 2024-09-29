class Solution {
    bool containsAllVowels(const unordered_set<char>& vowelSet) {
        return vowelSet.size() == 5; // The size should be 5 because there are 5 vowels ('a', 'e', 'i', 'o', 'u')
    }
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int totalCount = 0;

        // Iterate through all possible starting points of substrings
        for (int start = 0; start < n; start++) {
            unordered_set<char> vowelSet;
            int consonantCount = 0;

            // Iterate through all possible substrings starting at 'start'
            for (int end = start; end < n; end++) {
                char ch = word[end];

                // Check if the character is a vowel
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowelSet.insert(ch);
                } 
                // Otherwise, it is a consonant
                else if (isalpha(ch)) {
                    consonantCount++;
                }

                // Check if this substring contains all vowels and has exactly k consonants
                if (containsAllVowels(vowelSet) && consonantCount == k) {
                    totalCount++;
                }
            }
        }

        return totalCount;
    }
};