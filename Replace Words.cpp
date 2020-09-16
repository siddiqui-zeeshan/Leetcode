class Trie{
public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) { node->next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isword = true;
    }

    string search(string word) {
        Trie* node = this;
        string w = "";
        for (char ch : word) {
            //cout<<"a ";
            if (!node->next.count(ch)) 
            { 
                //cout<<w<<" "<<word<<endl;
                return word; 
            }
            w = w + ch;
            node = node->next[ch];
            if(node->isword)
                return w;
        }
        
        return w;
    }

private:
    unordered_map<char, Trie*> next = {};
    bool isword = false;
};

class Solution {
public:
    
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* trie = new Trie();
        for(auto i : dict)
        {
            trie->insert(i);
        }
        string w = "";
        string res = "";
        for(auto i : sentence)
        {
            if(i == ' ')
            {
                string temp = trie->search(w);
                res = res + temp + " ";
                w = "";
            }
            else
            {
                w = w + i;
            }
        }
        string temp = trie->search(w);
        res = res + temp;
        w = "";
        return res;
    }
};
