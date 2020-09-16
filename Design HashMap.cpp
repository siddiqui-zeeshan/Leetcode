class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<vector<pair<int,int>>> s;
    MyHashMap() {
        for(int i = 0; i < 10000; i++)
        {
            s.push_back({});
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = key % 10000;
        if(!contains(key))
            s[k].push_back({key, value});
        else
        {
            int pos = 0;
            for(int i = 0; i < s[k].size(); i++)
            {
                if(s[k][i].first == key)
                {
                    pos = i;
                    break;
                }
            }
            s[k][pos] = {key, value};
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k = key % 10000;
        if(!contains(key))
            return -1;
        else
        {
            int pos = 0;
            for(int i = 0; i < s[k].size(); i++)
            {
                if(s[k][i].first == key)
                {
                    pos = i;
                    break;
                }
            }
            return s[k][pos].second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k = key % 10000;
        int pos = 0;
        if(s[k].empty())
            return;
        bool flag = false;
        for(auto i : s[k])
        {
            if(i.first == key)
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
    
    bool contains(int key)
    {
        int k = key % 10000;
        if(s[k].empty()){
            return false;
        }
        for(auto i : s[k])
        {
            if(i.first == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
