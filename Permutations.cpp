class Solution {
public:
    
    void perm(vector<int>& nums, vector<int>& A, vector<vector<int>>& res)
    {
        if(nums.size()==0)
            res.push_back(A);
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            nums.erase(nums.begin()+i);
            A.push_back(x);
            perm(nums, A, res);
            nums.insert(nums.begin()+i,x);
            A.erase(A.end()-1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> A;
        perm(nums, A, res);
        return res;
    }
};
