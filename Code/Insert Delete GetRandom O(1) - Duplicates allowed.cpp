class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> rec;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        rec.push_back(val);
        mp[val].insert(rec.size() - 1);
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        auto it = mp.find(val);
        auto free_pos = *it->second.begin();
        it->second.erase(it->second.begin());
        rec[free_pos] = rec.back();
        mp[rec.back()].insert(free_pos);
        mp[rec.back()].erase(rec.size() - 1);
        rec.pop_back();
        if (it->second.size() == 0) 
            mp.erase(it);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return rec[rand() % rec.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
