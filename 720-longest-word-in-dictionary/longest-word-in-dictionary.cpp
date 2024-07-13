struct Node
{
    Node *links[26];
    bool flag = false;
    bool contains(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setend()
    {
        flag = true;
    }
    bool isend()
    {
        return flag;
    }
};
class Trie
{
    Node *root;
public:

    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->contains(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }
    bool check(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            node=node->get(word[i]);
            if (!node || !node->isend())
            {
             return false;   
            }
        }
        return true;
    }
};
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        int n = words.size();
        Trie trie;
        sort(words.begin(), words.end());
        for (int i = 0; i < n; i++)
        {
            trie.insert(words[i]);
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (trie.check(words[i]) && ans.size() < words[i].size())
            {
                ans = words[i];
            }
        }
           return ans;
    }
 
};