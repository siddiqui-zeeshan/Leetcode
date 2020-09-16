class Solution {
public:
    bool dfs(unordered_map<int, bool>& rec, int pool, int nums, int tot)
    {
        if(tot <= 0)
            return false;
        auto it = rec.find(pool);
        if(it != rec.end())
            return it->second;
        for(int i = 1; i <= nums; i++)
        {
            int bit = 1 << i;
            if(pool & bit)
                continue;
            
            if(!dfs(rec, pool | bit, nums, tot - i))
            {
                return rec[pool] = true;
                
            }
                   
        }
        return rec[pool] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        
        if(desiredTotal == 0) return true;
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return false;        
        
        unordered_map<int, bool> rec;
        
        return dfs(rec, 0, maxChoosableInteger, desiredTotal);
    }
};
