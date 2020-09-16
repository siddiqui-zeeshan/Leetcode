class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string w = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                reverse(w.begin(), w.end());
                res += w;
                res += " ";
                w = "";
            }
            else
            {
                w += s[i];
            }
        }
        reverse(w.begin(), w.end());
        res += w;
        return res;
    }
};
