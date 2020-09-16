class Solution {
public:
    string modifyString(string s) {
        int l = s.length();
        if(l == 1)
        {
            if(s[0] == '?')
                return "a";
            else
                return s;
        }
        if(s[0] == '?' && s[1] != '?')
        {
            s[0] = ((s[1] - 'a' + 1) % 26) + 'a';
        }
        else if(s[0] == '?' && s[1] == '?')
        {
            s[0] = 'a';
        }
        for(int i = 1; i < l - 1; i++)
        {
            if(s[i] != '?')
                continue;
            if(s[i + 1] == '?')
            {
                s[i] = ((s[i - 1] - 'a' + 1) % 26) + 'a';
            }
            else
            {
                if(s[i - 1] + 1 == s[i + 1])
                    s[i] = ((s[i + 1] - 'a' + 1) % 26) + 'a';
                else 
                    s[i] = ((s[i - 1] - 'a' + 1) % 26) + 'a';
            }
        }
        if(s[l - 1] == '?')
        {
            s[l - 1] = ((s[l - 2] - 'a' + 1) % 26) + 'a';
        }
        return s;
    }
};
