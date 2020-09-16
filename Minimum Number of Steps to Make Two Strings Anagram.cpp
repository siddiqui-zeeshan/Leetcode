class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);
        for(auto i : s)
        {
            f1[i - 'a']++;
        }
        for(auto i: t)
        {
            f2[i - 'a']++;
        }
        int c1 = 0; 
        int c2 = 0;
        for(int i = 0; i < 26; i++)
        {
            int a = min(f1[i], f2[i]);
            f1[i] -= a;
            f2[i] -= a;
            c1 += f1[i];
            c2 += f2[i];
        }
        return min(c1, c2);
    }
};
