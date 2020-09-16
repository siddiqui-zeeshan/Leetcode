class Solution {
public:
    bool detectCapitalUse(string word) {
        int nc = 0;
        for(auto i : word)
        {
            if(i >= 'A' && i <= 'Z')
                nc++;
        }
        if(nc == 0 || nc == word.length())
            return true;
        if(nc == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;
        return false;
    }
};
