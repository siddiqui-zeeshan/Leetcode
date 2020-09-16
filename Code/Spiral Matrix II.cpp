class Solution {
public:
    vector<vector<int>> generateMatrix(int A) {
        vector<vector<int>> arr(A);
    for(int i=0;i<A;i++)
    {
        for(int j=0;j<A;j++)
        arr[i].push_back(0);
    }
    int row=A-1;
    int col=row;
    int rs=0,cs=0;
    int n=1;
    while(rs<=row)
    {
        for(int i=cs;i<=col;i++)
        {
           arr[rs][i]=n;
           n++;
        }
        rs++;
        for(int i=rs;i<=row;i++)
        {
            arr[i][col]=n;
            n++;
        }
        col--;
        for(int i=col;i>=cs;i--)
        {
            arr[row][i]=n;
            n++;
        }
        row--;
        for(int i=row;i>=rs;i--)
        {
            arr[i][cs]=n;
            n++;
        }
        cs++;
    }
    return arr;
    }
};
