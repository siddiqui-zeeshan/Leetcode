class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(auto i : arr)
        {
            if(i % 2 == 0)
                count = 0;
            if(i % 2 != 0)
                count++;
            if(count >= 3)
                return true;
        }
        return false;
    }
};
