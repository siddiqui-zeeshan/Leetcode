class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> rec;
        vector<int> res;
        for(int i = 0 ; i < nums.size(); i++)
        {
            rec[nums[i]]++;
        }
        for(auto i = rec.begin(); i != rec.end(); i++)
        {
            if(i->second == 1)
                res.push_back(i->first);
            
        }
        return res;
    }
};
