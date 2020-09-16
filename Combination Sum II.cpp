class Solution {
public:
    void comb(set<vector<int>> &res, vector<int> &A, vector<int> &candidates, int target, int pos)
    {
        if(!target)
        {
            vector<int> B=A; 
            sort(B.begin(),B.end());
            res.insert(B);
        }
        
        
        for(int i=pos;i!=candidates.size() && target >= candidates[i];i++)
            {
                int x=candidates[i];
                candidates.erase(candidates.begin()+i);
                A.push_back(x);
                comb(res,A,candidates,target-x,i);
                candidates.insert(candidates.begin()+i,x);
                A.pop_back();
                
            }
    }
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> res;
        vector<vector<int>> res1;
        vector<int> A;
        comb(res, A, candidates, target, 0);
        set<vector<int>>:: iterator itr;
    for(itr=res.begin();itr!=res.end();itr++)
    {
        res1.push_back(*itr);
    }
        return res1;
        
    }
};
