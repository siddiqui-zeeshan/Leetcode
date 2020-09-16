class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& A, int k) {
        unordered_map<int, int> rec;
        
        for(int i = 0; i < A.size(); i++)
        {
            if(rec.find(A[i]) == rec.end())
                rec[A[i]] = i;
            else
            {
                if(abs(rec[A[i]] - i) <= k)
                    return true;
                else
                    rec[A[i]] = i;
            }
        }
        return false;
        
    }
};
