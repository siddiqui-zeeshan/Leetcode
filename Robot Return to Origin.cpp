class Solution {
public:
    bool judgeCircle(string moves) {
        int l , r, u, d;
        l = r = u = d = 0;
        for(auto i : moves)
            int x = i == 'U' ? u++ : i == 'D' ? d++ : i == 'R' ? r++ : i == 'L' ? l++ : 0;
        return r == l && u == d;
    }
};
