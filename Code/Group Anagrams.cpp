class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        int n=A.size();
        unordered_map<string,vector<string>> rec;
        for(int i=0;i<n;i++)
        {
            string t=A[i];
            sort(t.begin(), t.end());
            rec[t].push_back(A[i]);
        }
        vector<vector<string>> res;
        for(auto i=rec.begin();i!=rec.end();i++)
        {
            res.push_back(i->second);
        }
        return res;
    }
};
