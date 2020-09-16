class Solution {
public:
    void dfs(int v, vector<vector<int>>& rooms, vector<bool>& vis)
    {
        vis[v] = true;
        for(int i = 0; i < rooms[v].size(); i++)
        {
            if(!vis[rooms[v][i]])
                dfs(rooms[v][i], rooms, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(0, rooms, vis);
        for(auto i : vis)
        {
            if(!i)
                return false;
        }
        return true;
    }
};
