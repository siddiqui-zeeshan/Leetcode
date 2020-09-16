class SubrectangleQueries {
public:
    vector<vector<int>> rec;
    vector<vector<int>> arr;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        arr = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        rec.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for(int i = rec.size() - 1; i >= 0; i--)
        {
            if(row >= rec[i][0] && row <= rec[i][2] && col >= rec[i][1] && col <= rec[i][3])
                return rec[i][4];
        }
        return arr[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
