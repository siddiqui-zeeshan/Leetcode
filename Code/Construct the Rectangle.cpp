class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = sqrt(area);
        if(l * l == area)
            return {l , l};
        while(area % l != 0)
        {
            l++;
        }
        int a = max (l, area / l);
        int b = min(l, area / l);
        return {a, b};
    }
};
