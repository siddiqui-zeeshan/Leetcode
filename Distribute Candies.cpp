class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> rec;
        for(auto i :candies)
            rec[i]++;
        if(rec.size() > candies.size() / 2)
            return candies.size() / 2;
        else
            return rec.size();
    }
};
