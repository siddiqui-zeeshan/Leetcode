class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if(nums.empty())
            return res;
        unordered_map<int,int> rec;
        for(auto i : nums)
        {
            rec[i]++;
        }
        for(auto i : rec)
        {
            if(i.second != 1)
                res.push_back(i.first);
        }
        return res;
    }
};
