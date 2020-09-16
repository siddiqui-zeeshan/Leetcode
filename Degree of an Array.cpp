class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> rec;
        if(nums.size() == 1)
            return 1;
        for(auto i : nums)
        {
            rec[i]++;
        }
        int fr;
        fr = 0;
        for(auto i : rec)
        {
            if(i.second > fr){
                fr = i.second;
            }
        }
        vector<int> v;
        for(auto i : rec)
        {
            if(i.second == fr)
                v.push_back(i.first);
        }
        int ans = INT_MAX;
        for(auto num : v)
        {
            int p1, p2;
            p1 = 0;
            p2 = nums.size() - 1;
            while(nums[p1] != num)
            p1++;
            while(nums[p2] != num)
            p2--;
            ans = min(p2 - p1 + 1, ans);
        }
        return ans;
    }
};
