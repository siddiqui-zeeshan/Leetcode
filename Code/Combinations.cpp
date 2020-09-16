class Solution {
public:
    
    void comb(vector<vector<int>> &res, vector<int> &A, vector<int> &nums, int k,int pos)
    {
        if(k==0)
        {
            vector<int> B=A; 
            sort(B.begin(),B.end());
            res.push_back(B);
        }
        
            for(int i=pos;i<nums.size();i++)
            {
                int x=nums[i];
                nums.erase(nums.begin()+i);
                A.push_back(x);
                comb(res,A,nums,k-1,i);
                nums.insert(nums.begin()+i,x);
                A.erase(A.end()-1);
                
            }
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> res;
    vector<int> A;
    for(int i=1;i<=n;i++)
        nums.push_back(i);
    comb(res,A,nums,k,0);
        return res;
    }
};
