class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> s;//(10000, vector<int>());
    MyHashSet() {
        for(int i = 0; i < 10000; i++)
        {
            s.push_back({});
        }
    }
    
    void add(int key) {
        int k = key % 10000;
        if(!contains(key))
            s[k].push_back(key);
    }
    
    void remove(int key) {
        int k = key % 10000;
        int pos = 0;
        if(s[k].empty())
            return;
        bool flag = false;
        for(auto i : s[k])
        {
            if(i == key)
            {
                flag = true;
                break;
            }
            pos++;
        }
        if(flag)
        {
            //cout<<"erase "<<s[k].size()<<endl;
            s[k].erase(s[k].begin() + pos);
            //cout<<"erase "<<s[k].size()<<endl;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k = key % 10000;
        if(s[k].empty()){
            //cout<<key<<" ";
            return false;
        }
        for(auto i : s[k])
        {
            //cout<<key<<" "<<i<<endl;
            if(i == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
