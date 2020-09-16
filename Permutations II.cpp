class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<vector<int>> res;
        res.push_back(A);
        while(next_permutation(A.begin(), A.end()))
        {
            res.push_back(A);
        }
        return res;
    }
};
