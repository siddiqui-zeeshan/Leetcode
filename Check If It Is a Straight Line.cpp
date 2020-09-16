class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& A) {
        if(A.size() <= 2)
            return true;
        int  y1 = A[0][1];
        int x1 = A[0][0];
        int y2 = A[1][1];
        int x2 = A[1][0];
        
        for(int i = 2; i < A.size(); i++)
        {
            int x = (y2 - y1) * (A[i][0] - x1);
            int y = (x2 - x1) * (A[i][1] - y1);
            
            if(x != y)
            {
                return false;
            }
        }
        return true;
    }
};
