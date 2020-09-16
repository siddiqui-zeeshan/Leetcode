class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        vector <int> mat;
        for(int i=0;i<row;i++)
            for(int j=0;j<row;j++)
            {
                mat.push_back(matrix[i][j]);
            }
        sort(mat.begin(),mat.end());
        //for(int i=0;i<row*row;i++)
            //cout<<mat[i]<<" ";
        return mat[k-1];
    }
};
