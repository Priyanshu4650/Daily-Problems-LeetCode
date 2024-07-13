struct TrieNode {
    TrieNode* children[26];
    int count;
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        count = 0;
        isEnd = false;
    }
};
class Trie {
private:
    TrieNode* root;

    void insertWord(const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
        curr->count++;
    }

    void collectWords(TrieNode* node, vector<pair<string, int>>& freqPairs, string& prefix) {
        if (node->isEnd) {
            freqPairs.push_back({prefix, node->count});
        }
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                prefix.push_back('a' + i);
                collectWords(node->children[i], freqPairs, prefix);
                prefix.pop_back();
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const vector<string>& words) {
        for (const auto& word : words) {
            insertWord(word);
        }
    }

    vector<pair<string, int>> getFrequencies() {
        vector<pair<string, int>> freqPairs;
        string prefix;
        collectWords(root, freqPairs, prefix);
        return freqPairs;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        
        Trie trie;
        trie.insert(words);
        
        // Step 1: Get frequency pairs from Trie
        vector<pair<string, int>> freqPairs = trie.getFrequencies();
        
        // Step 2: Sort frequency pairs based on count and word lexicographically
        sort(freqPairs.begin(), freqPairs.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        
        // Step 3: Extract the top k frequent words
        for (int i = 0; i < k; ++i) {
            result.push_back(freqPairs[i].first);
        }
        
        return result;
    }
};
