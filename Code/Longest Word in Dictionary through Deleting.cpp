class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        map<int, set<string>, greater<int>> table;
        for (auto word : d) {
            if (isSubsequence(word, s)) {
                table[word.size()].insert(word);
            }
        }
        return table.empty() ? "" : *(table.begin()->second.begin());
    }
    
    bool isSubsequence(string s, string t) {
        int m = 0;
        int n = 0;
        while (n < t.size() && m < s.size()) {
            if (t[n] == s[m]) {
                ++ n;
                ++ m;
            } else {
                ++ n;
            }
        }
        return m == s.size();
    }
};
