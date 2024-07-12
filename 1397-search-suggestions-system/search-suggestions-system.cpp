class TrieNode {
public :
	TrieNode *childNode[26];
	bool wordEnd;

	TrieNode() {
		wordEnd = false;
		for(int i=0;i<26;i++) {
			childNode[i] = NULL;
		}
	}
};

class Trie {
public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *ptr = root;

        for (char c : word) {
            int index = c - 'a';

            if (ptr->childNode[index] == nullptr) {
                ptr->childNode[index] = new TrieNode();
            }

            ptr = ptr->childNode[index];
        }

        ptr->wordEnd = true;
    }

    void collectWords(TrieNode *node, string prefix, vector<string> &results) {
        if (node == nullptr) return;

        if (node->wordEnd) {
            results.push_back(prefix);
            if (results.size() >= 3) return;
        }

        for (int i = 0; i < 26; ++i) {
            if (node->childNode[i] != nullptr) {
                collectWords(node->childNode[i], prefix + char('a' + i), results);
                if (results.size() >= 3) return; 
            }
        }
    }

    vector<string> search(string prefix) {
        TrieNode *ptr = root;
        vector<string> results;

        for (char c : prefix) {
            int index = c - 'a';

            if (ptr->childNode[index] == nullptr) {
                return results;
            }

            ptr = ptr->childNode[index];
        }

        collectWords(ptr, prefix, results);

        sort(results.begin(), results.end());

        if (results.size() > 3) {
            results.resize(3);
        }

        return results;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie *obj = new Trie();

        for(auto product : products) {
            obj->insert(product);
        }

        vector<vector<string>> res;

        string temp = "";
        for(auto c : searchWord) {
            temp += c;

            res.push_back(obj->search(temp));
        }

        return res;
    }
};