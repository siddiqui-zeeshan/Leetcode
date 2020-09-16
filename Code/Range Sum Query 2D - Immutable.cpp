class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& A) {
        if(A.empty())
        sum;
        else
        {
        vector<vector<int>> temp(A.size() + 1, vector<int>(A[0].size() + 1, 0));
        cout<<temp.size()<<" "<<temp[0].size()<<endl;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[0].size(); j++)
            {
                temp[i + 1][j + 1] = temp[i + 1][j] + A[i][j];                
            }
        }
        sum = temp;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1 + 1; i <= row2 + 1; i++)
        {
            res += sum[i][col2 + 1] - sum[i][col1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
