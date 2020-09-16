class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.empty() && nums1.empty())
            return {};
        unordered_map<int,int> mp;
        if(nums2.size() > 0)
        {
            stack<int> s;
            s.push(nums2[nums2.size() - 1]);
            mp[nums2[nums2.size() - 1]] = -1;
            for(int i = nums2.size() - 2; i >= 0; i--)
            {
                //cout<<s.top()<<" ";
                if(nums2[i] < s.top())
                {
                    //cout<<"a ";
                    mp[nums2[i]] = s.top();
                    s.push(nums2[i]);
                }
                else
                {
                    while(!s.empty() && nums2[i] > s.top())
                        s.pop();
                    if(s.empty())
                        mp[nums2[i]] = -1;
                    else
                        mp[nums2[i]] = s.top();
                    s.push(nums2[i]);
                }
            }
        }
        vector<int> res;
        for(auto i : nums1)
        {
            if(mp.find(i) == mp.end())
            {
                res.push_back(-1);
                continue;
            }
            res.push_back(mp[i]);
        }
        return res;
    }
};
