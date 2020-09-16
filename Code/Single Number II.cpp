class Solution {
public:
    int singleNumber(vector<int>& A) {
        unordered_map<int, int> rec;
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            rec[A[i]]++;
        }
        for(auto i=rec.begin();i!=rec.end();i++)
        {
            if(i->second == 1)
                return i->first;
        }
        return -1;
    }
};
