class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() == 00)
            return 0;
        map<int, int> rec;
        for(auto i : nums)
            rec[i]++;
        auto i = rec.begin();
        i++;
        int mc = 0;
        for(; i != rec.end(); i++)
        {
            auto temp = i;
            temp--;
            
            if(i->first == temp->first + 1){
                mc = max(mc, i->second + temp->second);
                ///cout<<i->first<<" "<<temp->first<<endl;
            }
        }
        return mc;
    }
};
