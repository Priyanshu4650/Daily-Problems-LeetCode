class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.size() < k) {
            string newWord = "";
            for(int i=0;i<word.size();i++) {
                newWord += (word[i] - 'a' + 1) % 26 + 'a'; 
            }

            word += newWord;
        }

        return word[k - 1];
    }
};