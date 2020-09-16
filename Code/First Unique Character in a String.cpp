class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> rec;
        for(auto i : s)
        {
            rec[i]++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(rec[s[i]] == 1)
                return  i;
        }
        return -1;
    }
};
