class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> rec;
        for(auto i : nums)
        {
            rec.insert(i);
        }
        for(int i = 1; i <= nums.size(); i++)
        {
            if(rec.find(i) == rec.end())
                res.push_back(i);
        }
        return res;
    }
};
