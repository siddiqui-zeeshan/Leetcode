class Solution {
public:
    bool isVowel(char a)
    {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'
            || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U';
    }
    string reverseVowels(string s) {
        int l, r;
        l = 0;
        r = s.length() - 1;
        while(l < r)
        {
            while(l < s.length() && !isVowel(s[l]))
            {
                l++;
            }
            while(r >= 0 && !isVowel(s[r]))
            {
                r--;
            }
            if(l < r)
            {
                char t = s[l];
                s[l] = s[r];
                s[r] = t;
                l++;
                r--;
            }
            else
            {
                break;
            }
        }
        return s;
    }
};
