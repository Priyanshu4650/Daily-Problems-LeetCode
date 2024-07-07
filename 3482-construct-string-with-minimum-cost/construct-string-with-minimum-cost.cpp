#include <vector>
#include <string>
#include <climits>
#include <algorithm>

class TrieNode {
public:
    TrieNode* children[26];
    int cost;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        cost = INT_MAX;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word, int cost) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->cost = std::min(node->cost, cost);
    }

    int search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                return INT_MAX;
            }
            node = node->children[idx];
        }
        return node->cost;
    }
};

class Solution {
public:
    int minimumCost(const std::string& target, const std::vector<std::string>& words, const std::vector<int>& costs) {
        Trie trie;
        for (size_t i = 0; i < words.size(); ++i) {
            trie.insert(words[i], costs[i]);
        }

        std::vector<int> dp(target.size() + 1, INT_MAX);
        dp[0] = 0;

        for (size_t i = 0; i < target.size(); ++i) {
            if (dp[i] == INT_MAX) {
                continue;
            }
            TrieNode* node = trie.root;
            for (size_t j = i; j < target.size(); ++j) {
                int idx = target[j] - 'a';
                if (!node->children[idx]) {
                    break;
                }
                node = node->children[idx];
                if (node->cost != INT_MAX) {
                    dp[j + 1] = std::min(dp[j + 1], dp[i] + node->cost);
                }
            }
        }

        return dp[target.size()] == INT_MAX ? -1 : dp[target.size()];
    }
};
