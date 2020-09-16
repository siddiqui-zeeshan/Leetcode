class Solution {
public:
    int r, c;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    
        r = grid.size();
        c = grid[0].size();
        return go(0, 0, grid);
    }
    bool ok(int y, int x) {
        if (y >= r || x >= c || y < 0 || x < 0) {
            return 0;
        }        
        return 1;
    }
    bool go(int y, int x, vector<vector<int>>& grid) {
        if (y == r-1 && x == c-1) {
            return 1;
        }
        if (grid[y][x] == 0) {
            return 0;
        }
        int tmp = grid[y][x];
        grid[y][x] = 0;
        if (tmp == 1) {
            if ((ok(y, x+1) && (grid[y][x+1] == 1 || grid[y][x+1] == 3 || grid[y][x+1] == 5)) && go(y, x+1, grid)) {
                return 1;
            }
            if ((ok(y, x-1) && (grid[y][x-1] == 1 || grid[y][x-1] == 4 || grid[y][x-1] == 6)) && go(y, x-1, grid)) {
                return 1;
            }
        }
        else if (tmp == 2) {
            if ((ok(y+1, x) && (grid[y+1][x] == 2 || grid[y+1][x] == 5 || grid[y+1][x] == 6)) && go(y+1, x, grid)) {
                return 1;
            }
            if ((ok(y-1, x) && (grid[y-1][x] == 2 || grid[y-1][x] == 3 || grid[y-1][x] == 4)) && go(y-1, x, grid)) {
                return 1;
            }
        }
        else if (tmp == 3) {
            if ((ok(y, x-1) && (grid[y][x-1] == 1 || grid[y][x-1] == 4 || grid[y][x-1] == 6)) && go(y, x-1, grid)) {
                return 1;
            }
            if ((ok(y+1, x) && (grid[y+1][x] == 2 || grid[y+1][x] == 5 || grid[y+1][x] == 6)) && go(y+1, x, grid)) {
                return 1;
            }
        }
        else if (tmp == 4) {
            if ((ok(y+1, x) && (grid[y+1][x] == 2 || grid[y+1][x] == 5 || grid[y+1][x] == 6)) && go(y+1, x, grid)) {
                return 1;
            }
            if ((ok(y, x+1) && (grid[y][x+1] == 1 || grid[y][x+1] == 3 || grid[y][x+1] == 5)) && go(y, x+1, grid)) {
                return 1;
            }
        }
        else if (tmp == 5) {
            if ((ok(y, x-1) && (grid[y][x-1] == 1 || grid[y][x-1] == 4 || grid[y][x-1] == 6)) && go(y, x-1, grid)) {
                return 1;
            }
            if ((ok(y-1, x) && (grid[y-1][x] == 2 || grid[y-1][x] == 3 || grid[y-1][x] == 4)) && go(y-1, x, grid)) {
                return 1;
            }
        }
        else {
            if ((ok(y, x+1) && (grid[y][x+1] == 1 || grid[y][x+1] == 3 || grid[y][x+1] == 5)) && go(y, x+1, grid)) {
                return 1;
            }
            if ((ok(y-1, x) && (grid[y-1][x] == 2 || grid[y-1][x] == 3 || grid[y-1][x] == 4)) && go(y-1, x, grid)) {
                return 1;
            }
        }
        return 0;
    }
};
