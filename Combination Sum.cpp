class Solution {
public:
    void comb(vector<vector<int>> &res, vector<int> &A, vector<int> &candidates, int target, int pos)
    {
        if(!target)
        {
            res.push_back(A);
            return;
        }
        
        
        for(int i=pos;i!=candidates.size() && target >= candidates[i];i++)
            {
                int x=candidates[i];
                A.push_back(x);
                comb(res,A,candidates,target-x,i);
                A.pop_back();
                
            }
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> A;
        comb(res, A, candidates, target, 0);
        return res;
    }
};
