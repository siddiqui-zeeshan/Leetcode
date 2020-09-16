class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        bool result=false;
        for(int i=0;i<=n;i++)
        {
            int l=0;
            int u=m;
            int mid;
            if(target>=matrix[0][i] && target<=matrix[m][i])
            {
                while(l<=u)
                {
                    mid=l+(u-l)/2;
                    if(matrix[mid][i]==target)
                        {
                        result=true;
                        break;
                    }
                    if(matrix[mid][i]>target)
                        u=mid-1;
                    if(matrix[mid][i]<target)
                        l=mid+1;
                }
            }
        }
        return result;
    }
};
