class Solution {
public:
    static bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
    { 
       return (a.first > b.first); 
    } 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> rec;
        for(int i = 0; i < nums.size(); i++)
        {
            rec[nums[i]]++;
        }
        vector<pair<int,int>> res;
        for(auto i = rec.begin(); i != rec.end(); i++)
        {
            res.push_back(make_pair(i->second, i->first));
        }
        sort(res.begin(), res.end(), sortinrev);
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(res[i].second);
        }
        return ans;
    }
};
