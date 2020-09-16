class MagicDictionary {
public:
    /** Initialize your data structure here. */
    vector<string> d;
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto i : dict)
        {
            d.push_back(i);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int count = 0;
        for(auto i : d)
        {
            if(word.length() != i.length())
                continue;
            count = 0;
            for(int j = 0; j < i.length(); j++)
            {
                if(i[j] != word[j])
                    count++;
            }
            if(count == 1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
