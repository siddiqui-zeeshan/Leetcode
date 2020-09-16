class Solution {
public:
    void transform(int pos, string s, vector<string>& ans)
    {
        if(pos == s.length())
        {
            ans.push_back(s);
            return;
        }
        transform(pos + 1, s, ans);
        if(s[pos] >= 'a' && s[pos] <= 'z')
        {
            s[pos] = s[pos] -'a' + 'A';
            transform(pos + 1, s, ans);
        }
        else if(s[pos] >= 'A' && s[pos] <= 'Z')
        {
            s[pos] = s[pos] - 'A' + 'a';
            transform(pos + 1, s, ans);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        transform(0, S, ans);
        
        return ans;
    }
};
