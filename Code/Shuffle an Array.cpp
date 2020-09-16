class Solution {
public:
    vector<int> backup;
    Solution(vector<int>& nums) {
        backup = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return backup;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = backup.size();
        vector<int> res(n);
        unordered_set<int> s;
        
        while(s.size() < n)
        {
            int pos = rand() % n;
            s.insert(pos);
        }
        int pos = 0;
        for(auto i = s.begin(); i != s.end(); i++)
        {
            res[pos] = backup[*i];
            pos++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
