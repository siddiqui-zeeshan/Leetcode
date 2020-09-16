class Solution {
public:
    bool canConstruct(string r, string m) {
        int f1[26];
        int f2[26];
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        
        for(int i = 0; i < r.length(); i++)
        {
            f1[r[i] - 'a']++;
        }
        for(int i = 0; i < m.length(); i++)
        {
            f2[m[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++)
        {
            //cout<<f1[i]<<" "<<f2[i]<<endl;
            if(f1[i] > f2[i])
                return false;
        }
        return true;
    }
};
