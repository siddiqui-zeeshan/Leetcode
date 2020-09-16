class Solution {
public:
    string pushDominoes(string s) {
        if(s.size() == 0)
            return s;
        vector<int> l(s.size(), -1), r(s.size(), -1);
        r[0] = s[0] == 'R'? 0 : -1;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == 'R')
                r[i] = 0;
            else if(s[i] == '.')
            {
                if(r[i - 1] != -1)
                    r[i] = r[i - 1] + 1;
            }
        }
        l[l.size() - 1] = s[s.size() - 1] == 'L' ? 0 : -1;
        for(int i = s.length() - 2; i >= 0; i--)
        {
            if(s[i] == 'L')
            {
                l[i] = 0;
            }
            else if(s[i] == '.')
            {
                if(l[i + 1] != -1)
                    l[i] = l[i + 1] + 1;
            }
        }
        // for(auto i : r)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(auto i : l)
        //     cout<<i<<" ";
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'L' || s[i] == 'R')
                continue;
            if(r[i] == l[i])
                continue;
            if(r[i] != -1 && l[i] == -1)
                s[i] = 'R';
            else if(r[i] == -1 && l[i] != -1)
                s[i] = 'L';
            else if(r[i] < l[i])
                s[i] = 'R';
            else if(l[i] < r[i])
                s[i] = 'L';
        }
        return s;
    }
};
