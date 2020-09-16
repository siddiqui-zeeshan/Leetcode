class Solution {
public:
    int find(vector<int>& dsu, int i)
    {
        if(dsu[i] != i)
            dsu[i] = find(dsu, dsu[i]);
        return dsu[i];
    }
    void _union(vector<int>& dsu, int x, int y)
    {
        int xp = find(dsu, x);
        int yp = find(dsu, y);
        if(xp != yp)
            dsu[xp] = yp;
    }
    bool equationsPossible(vector<string>& eq) {
        vector<int> dsu(26, 0);
        for(int i = 0; i < 26; i++)
        {
            dsu[i] = i;
        }
        for(int i = 0; i < eq.size(); i++)
        {
            if(eq[i][1] == '='){
                int a = eq[i][0] - 'a';
                int b = eq[i][3] - 'a';
                _union(dsu, a, b);
            }
        }
        for(int i = 0; i < eq.size(); i++)
        {
            if(eq[i][1] == '!'){
                int a = eq[i][0] - 'a';
                int b = eq[i][3] - 'a';
                if(find(dsu, a) == find(dsu, b))
                    return false;
            }
        }
        return true;
    }
};
