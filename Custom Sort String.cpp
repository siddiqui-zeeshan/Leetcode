class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> f(26, 0);
        for(auto i : T)
        {
            f[i - 'a']++;
        }
        string s = "";
        for(auto i : S)
        {
            while(f[i - 'a'] > 0)
            {
                s = s + i;
                f[i - 'a']--;
            }
        }
            
        for(int i = 0; i < 26; i++)
        {
            while(f[i] > 0)
            {
                char ch = i + 'a';
                s += ch;
                f[i]--;
            }
        }
        return s;
    }
};
