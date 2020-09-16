class Solution {
public:
    void wiggleSort(vector<int>& A) {
        if(A.size() <= 1)
            return;
        vector<int> nums = A;
        sort(nums.begin(), nums.end(), greater<int>());
        int l = 0; 
        int r = nums.size() / 2;
        int i = 0;
        while(i < nums.size() && r < nums.size())
        {
            A[i] = nums[r];
            r++;
            i++;
            
            A[i] = nums[l];
            l++;
            i++;
        }
        if(r < nums.size() - 1)
        {
            A[A.size() - 1] = nums[r];
        }
    } 
};
