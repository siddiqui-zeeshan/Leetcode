class Trie {
public:
    Trie() {}

    void insert(string word, int n) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) { node->next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isword = true;
        node->id = n;
    }
    bool startsWith(string prefix, int &sum) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) { return false; }
            node = node->next[ch];
        }
        findSum(node, sum);
        return true;
    }
    void findSum(Trie* node, int &sum)
    {
        if(node->isword)
            sum += node->id;
        for(auto i : node->next)
        {
            findSum(i.second, sum);   
        }
    }

private:
    unordered_map<char, Trie*> next = {};
    bool isword = false;
    int id = 0;
};
class MapSum {
public:
    /** Initialize your data structure here. */
    Trie* trie = new Trie();
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        int s = 0;
        trie->startsWith(prefix, s);
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
