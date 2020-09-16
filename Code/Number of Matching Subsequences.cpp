class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.length(), sIdx = 0, tLen = t.length();
        for (int i=0; i<tLen && sIdx<sLen; i++) 
            if (t[i]==s[sIdx]) sIdx++;
        return sIdx==sLen;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        unordered_map<string, int> w;
        for(auto i : words)
            w[i]++;
        for(auto i : w)
        {
            if(isSubsequence(i.first, S))
                count += i.second;
        }
        return count;
    }
};
