class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
        unordered_map<string, int> rec;
        for(int i = 0; i < l1.size(); i++)
        {
            rec[l1[i]] = i;
        }
        map<int, vector<string>> res;
        for(int i = 0; i < l2.size(); i++)
        {
            if(rec.find(l2[i]) != rec.end())
            {
                res[i + rec[l2[i]]].push_back(l2[i]);
            }
        }
        vector<string> temp;
        return res.size() > 0 ? res.begin()->second : temp;
    }
};
