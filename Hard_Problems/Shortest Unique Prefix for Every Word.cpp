//Problem: Shortest Unique Prefix for Every Word
//Topic: Trie (Prefix Tree)
//Pattern: Hard

class Solution {
  public:
  struct TrieNode {
        TrieNode* child[26];
        int cnt;

        TrieNode() {
            cnt = 0;
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
            node->cnt++;
        }
    }

    string getPrefix(string &word) {
        TrieNode* node = root;
        string ans = "";

        for (char c : word) {
            int idx = c - 'a';
            node = node->child[idx];
            ans += c;

            if (node->cnt == 1)
                break;
        }

        return ans;
    }
    
    vector<string> findPrefixes(vector<string>& arr) {
        for (string &word : arr)
            insert(word);

        vector<string> res;
        for (string &word : arr)
            res.push_back(getPrefix(word));

        return res;
        
    }
};
