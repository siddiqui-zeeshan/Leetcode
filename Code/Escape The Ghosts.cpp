class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int d1 = abs(target[0]) + abs(target[1]);
        for(auto i : ghosts)
        {
            int d2 = abs(i[0] - target[0]) + abs(i[1] - target[1]);
            if(d1 >= d2)
                return !true;
            
        }
         return !false;
    }
};
