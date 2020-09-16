class TrieNode {
  public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        memset(children, NULL, sizeof(children));
        word = false;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word)
        {
            if(!node->children[c - 'a'])
            {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
private: 
    TrieNode* root = new TrieNode();
    bool search(string word, int pos, TrieNode* node)
    {
        for(int i = pos; i < word.size() && node; i++)
        {
            if(word[i] != '.')
            {
                node = node->children[word[i] - 'a'];
            }
            else
            {
                TrieNode* temp = node;
                for(int j = 0; j < 26; j++)
                {
                    
                    node = temp->children[j];
                    if(search(word, i + 1, node))
                        return true;
                }
            }
        }
        return node && node->word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
