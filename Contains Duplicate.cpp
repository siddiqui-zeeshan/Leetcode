class Solution {
public:
    bool containsDuplicate(vector<int>& A) {
        unordered_set<int> rec;
        for(int i = 0; i < A.size(); i++)
        {
            rec.insert(A[i]);
        }
        return A.size() != rec.size();
    }
};
