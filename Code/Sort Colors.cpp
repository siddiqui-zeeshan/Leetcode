class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> A(3);
        A[0]=0;
        A[1]=0;
        A[2]=0;
       for(int i=0;i<nums.size();i++)
       {
           A[nums[i]]++;
       }
        int j=0;
        for(int i=0; i<3;i++)
        while(A[i]!=0)
        {
            nums[j]=i;
            A[i]--;
            j++;
        }
    }
};
