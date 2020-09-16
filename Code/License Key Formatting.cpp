class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string s = "";
        int count = 0;
        for(int i = S.length() - 1; i >= 0; i--)
        {
            if(S[i] != '-')
            {
                if(count == K)
                {
                    s += '-';
                    count = 0;
                }
                string ch = "";
                ch += S[i];
                transform(ch.begin(), ch.end(), ch.begin(), ::toupper);
                s += ch;
                count++;
            }    
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
