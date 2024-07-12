class TrieNode {
public:
    TrieNode *childNode[26];
    bool wordEnd;

    TrieNode() {
        wordEnd = false;  // Initialize wordEnd to false initially
        for (int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode *root;

    bool searchRecursive(TrieNode *node, string &word, int index) {
        if (index == word.length()) {
            return node != nullptr && node->wordEnd;
        }

        char c = word[index];

        if (c == '.') {  // Handle wildcard dot
            for (int i = 0; i < 26; i++) {
                if (node->childNode[i] != nullptr && searchRecursive(node->childNode[i], word, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!isalpha(c) || !islower(c)) {
                return false;  // Return false for invalid characters
            }

            int charIndex = c - 'a';

            if (node->childNode[charIndex] == nullptr) {
                return false;  // Prefix does not exist
            }

            return searchRecursive(node->childNode[charIndex], word, index + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *ptr = root;

        for (char c : word) {
            if (!isalpha(c) || !islower(c)) {
                continue;  // Skip non-lowercase alphabetic characters
            }

            int index = c - 'a';

            if (ptr->childNode[index] == nullptr) {
                ptr->childNode[index] = new TrieNode();
            }

            ptr = ptr->childNode[index];
        }

        ptr->wordEnd = true;
    }
    
    bool search(string word) {
        return searchRecursive(root, word, 0);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */