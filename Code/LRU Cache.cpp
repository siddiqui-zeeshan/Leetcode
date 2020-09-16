class LRUCache {
    
private:
    unordered_map<int, int> lruKeyValue;
    list<int> freq;
    int cap = 0;
public:
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(lruKeyValue.find(key) != lruKeyValue.end())
        {
            freq.remove(key);
            freq.push_front(key);
            return lruKeyValue[key];
        }
        else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        
        if(lruKeyValue.size() == cap && lruKeyValue.find(key) == lruKeyValue.end())
        {
            lruKeyValue.erase(freq.back());
            freq.pop_back();
            freq.push_front(key);
            lruKeyValue[key] = value;  
        }
        else if(lruKeyValue.size() == cap && lruKeyValue.find(key) != lruKeyValue.end())
        {
            freq.remove(key);
            freq.push_front(key);
            lruKeyValue[key] = value;
        }
        else if(lruKeyValue.size() <= cap && lruKeyValue.find(key) == lruKeyValue.end())
        {
            freq.push_front(key);
            lruKeyValue[key] = value; 
        }
        else if(lruKeyValue.size() <= cap && lruKeyValue.find(key) != lruKeyValue.end())
        {
            freq.remove(key);
            freq.push_front(key);
            lruKeyValue[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
