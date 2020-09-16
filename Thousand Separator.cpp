class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        int l = s.length();
        if(l <= 3)
            return s;
        string ans = "";
        int pos = 1;
        for(int i = l - 1; i > 0; i--)
        {
            ans = s[i] + ans;
            if(pos % 3 == 0)
            {
                ans = "." + ans;
            }
            pos = (pos + 1) % 3;
        }
        ans = s[0] + ans;
        return ans;
    }
};
