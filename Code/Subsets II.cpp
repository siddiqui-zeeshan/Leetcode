class Solution {
public:
    void comb(set<vector<int>> &res, vector<int> &A, vector<int> &nums,int pos)
    {
        
            vector<int> B=A; 
            sort(B.begin(),B.end());
            res.insert(B);
        
            for(int i=pos;i<nums.size();i++)
            {
                int x=nums[i];
                nums.erase(nums.begin()+i);
                A.push_back(x);
                comb(res,A,nums,i);
                nums.insert(nums.begin()+i,x);
                A.pop_back();
                
            }
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> res1;
        vector<int> A;
        comb(res, A, nums, 0);
        set<vector<int>>:: iterator itr;
    for(itr=res.begin();itr!=res.end();itr++)
    {
        res1.push_back(*itr);
    }
        return res1;
    }
};
