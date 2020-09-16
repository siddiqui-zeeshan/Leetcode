class Solution {
public:
    bool isPalin(string s)
    {
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
    void funct(string s, int pos, vector<string> &v, vector<vector<string>> &res)
    {
        if(pos == s.length())
        {
            res.push_back(v);
        }
        for(int i = pos; i < s.length(); i++)
        {
            string t = s.substr(pos, i - pos + 1);
            if(isPalin(t))
            {
                v.push_back(t);
                funct(s, i + 1, v, res);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        funct(s, 0, v, res);
        return res;
    }
};
