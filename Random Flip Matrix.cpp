class Solution {
public:
    int row, col;
    unordered_map<int, unordered_map<int, int>> rec;
    Solution(int n_rows, int n_cols) {
        row = n_rows,
        col = n_cols; 
        rec.clear();
    }
    
    vector<int> flip() {
        
        int r, c;
        r = rand() % row;
        c = rand() % col;
        while(rec[r][c])
        {
            r = rand() % row;
            c = rand() % col;
        }
        rec[r][c] = 1;
        return {r, c};
    }
    
    void reset() {
        rec.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
