class Solution {
public:
    char findTheDifference(string s, string t) {
        int S=0,T=0;
        for(int i=0;i<s.length();i++)
            S=S^s[i];
        for(int i=0;i<t.length();i++)
            S=S^t[i];
        char ch=S;
        return ch;
    } 
};
