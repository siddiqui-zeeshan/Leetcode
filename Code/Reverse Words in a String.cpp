class Solution {
public:
    string trim(string s)
    {
        int l = s.length();
        int x = 0;
        while(x < l && s[x]==' ')
            x++;
        s = s.substr(x, l - x);
        x = s.length();
        x--;
        while(x > 0 && s[x] == ' ')
        {
            x--;
        }
        s = s.substr(0, x + 1);
        return s;
    }
    string reverseWords(string s) {
        s = trim(s);
        string w = "";
        string res = "";
        vector<string> rec;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ' || i == s.length() - 1)
            {
                if(i == s.length() - 1)
                {
                    w = w + s[i];
                }
                w = trim(w);
                if(w.length() > 0)
                rec.push_back(w);
                w = "";
            }
            else
            {
                w = w + s[i];
            }
        }
        for(int i = 0; i < rec.size(); i++)
        {
            res = rec[i] + " " + res;
        }
        return trim(res);
    }
};
