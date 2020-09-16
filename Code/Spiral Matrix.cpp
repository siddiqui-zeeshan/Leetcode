class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

    int r = matrix.size();
    int c = matrix[0].size();
    
    //sr: start row, sc: start column, er: end row, ec: end column
    int sr=0, sc=0, er=r-1, ec=c-1;
    while(sr <=er && sc <=ec) {
        if (sr == er) {
            for (int i=sc; i<=ec; i++)
                result.push_back(matrix[sr][i]);
            break;
        }
        if (sc==ec) {
            for (int i=sr; i<=er; i++) {
                result.push_back(matrix[i][sc]);
            }
            break;
        }

        for (int i=sc; i< ec; i++) {
            result.push_back(matrix[sr][i]);
        }
        for (int i=sr; i < er; i++) {
            result.push_back(matrix[i][ec]);
        }
        for (int i=ec; i>sc; i--) {
            result.push_back(matrix[er][i]);
        }
        for (int i=er; i>sr; i--) {
            result.push_back(matrix[i][sc]);
        }
        sr++;sc++;er--;ec--;
    }
    return result;
}
};
