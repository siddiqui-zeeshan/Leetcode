class Solution {
public:
    struct TrieNode
    {
        bool leaf=false;
        struct TrieNode* children[26];
        
    };
    struct TrieNode *create(void)
    {
        TrieNode* node=new TrieNode;
        node->leaf=false;
        for(int i=0;i<26;i++)
        {
            node->children[i]=NULL;
            
        }
        return node;
    }
    void insert(TrieNode* root, string s)
    {
        TrieNode* temp=root;
        for(int i=0;i<s.length();i++)
        {
            int key=s[i]-'a';
            if(!temp->children[key])
                temp->children[key]=create();
            temp=temp->children[key];
        }
        temp->leaf=true;
    }
    void longest(TrieNode* root, string &s, string &res)
    {
        if(root->leaf)
        {
            if(s.size()>res.size())
            {
                //cout<<s<<endl;
                res=s;
            }
            //return;
        }
        for(int i=0;i<26; i++)
        {
            if(root->children[i] && root->children[i]->leaf)
            {
                s.push_back(i+'a');
                longest(root->children[i], s, res);
                s.pop_back();
            }
        }  
    }
    string longestWord(vector<string>& words) 
    {
        TrieNode* root=create();
        for(int i=0;i<words.size();i++)
        {
            insert(root, words[i]);
        }
        string s="";
        string res="";
        longest(root, s, res);
        //cout<<s;
        return res;
    }
};
