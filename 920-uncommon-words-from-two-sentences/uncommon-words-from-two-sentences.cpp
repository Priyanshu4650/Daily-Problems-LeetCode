class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word = "";
        unordered_map<string, int> m1, m2;

        // Process the first string s1
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == ' ') {
                m1[word] += 1;
                word = "";
            }
            else {
                word += s1[i];
            }
        }
        if(word != "") {  // Add the last word from s1
            m1[word] += 1;
            word = "";
        }

        // Process the second string s2
        for(int i = 0; i < s2.size(); i++) {
            if(s2[i] == ' ') {
                m2[word] += 1;
                word = "";
            }
            else {
                word += s2[i];
            }
        }
        if(word != "") {  // Add the last word from s2
            m2[word] += 1;
            word = "";
        }

        // Find uncommon words
        set<string> res;

        // Add words that appear once in m1 and don't appear in m2
        for(auto it : m1) {
            if(it.second == 1 && m2[it.first] == 0) {
                res.insert(it.first);
            }
        }

        // Add words that appear once in m2 and don't appear in m1
        for(auto it : m2) {
            if(it.second == 1 && m1[it.first] == 0) {
                res.insert(it.first);
            }
        }

        // Convert set to vector
        vector<string> answer(res.begin(), res.end());
        return answer;
    }
};
