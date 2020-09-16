class Solution {
public:
    vector<int> majorityElement(vector<int>& A) {
        vector<int> res;
        if(A.size() < 2)
            return A;
        
        int a, b, c1, c2;
        a = b = c1 = c2 = 0;
        a = b = -1;
        for(int i = 0; i < A.size(); i++)
        {
            if(a == A[i])
                c1++;
            else if(b == A[i])
                c2++;
            else if(c1 == 0)
            {
                a = A[i];
                c1 = 1;
            }
            else if(c2 == 0)
            {
                b = A[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        
        for(int i = 0; i < A.size(); i++)
        {
            if(a == A[i])
                c1++;
            if(b == A[i])
                c2++;
        }
        if(c1 > A.size()/3)
            res.push_back(a);
        if(c2 > A.size()/3)
            res.push_back(b);
        return res;
    }
};
