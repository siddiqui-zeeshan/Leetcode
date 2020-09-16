class Solution {
public:
    string removeVowels(string S) {
        int l=S.length();
        string w="";
        for(int i=0;i<l;i++)
        {
            char x=S[i];
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            {
                int a=0;
            }
            else
                w=w+x;
        }
        return w;
    }
};
