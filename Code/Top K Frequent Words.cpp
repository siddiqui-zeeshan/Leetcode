class Solution {
public:
    static bool comp(const pair<int, string> &a, const pair<int, string> &b)
    {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(words.size() == 0)
            return {};
        unordered_map<string, int> rec;
        string w = "";
        for(auto i : words)
        {
            rec[i]++;
        }
        vector<pair<int, string>> v;
        for(auto i : rec)
        {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), comp);
        vector<string> res;
        int i = 0;
        while(k--)
            res.push_back(v[i++].second);
        //sort(res.begin(), res.end());
        return res;
    }
    
};
