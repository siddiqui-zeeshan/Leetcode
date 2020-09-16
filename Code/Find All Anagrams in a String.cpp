class Solution {
public:
    bool check(int f1[], int f2[])
    {
        for(int i = 0; i < 26; i++)
        {
            if(f1[i] != f2[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int l = p.size();
        int f1[26], f2[26];
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        vector<int> res;
        for(auto i : p)
        {
            f1[i - 'a']++;
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            f2[s[i] - 'a']++;
            if(i - l + 1 >= 0)
            {
                if(check(f1, f2))
                    res.push_back(i - l + 1);
                f2[s[i - l + 1] - 'a']--;
            }
        }
        return res;
    }
};
