class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++)
        {
            int l = s.size() - 1 - i;
            char t = s[i];
            s[i] = s[l];
            s[l] = t;
        }
    }
};
