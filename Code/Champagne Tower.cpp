class Solution {
public:
    double champagneTower(int p, int r, int c) {
        vector<vector<double>> rec(101);
        rec[0].push_back(p);
        for(int i = 1; i < 101; i++)
        {
            rec[i].push_back(max(rec[i - 1][0] - 1, 0.0) / 2);
            //rec[i - 1][0] = rec[i - 1][0] > 1 ? 1 : rec[i - 1][0];
            for(int j = 0; j < rec[i - 1].size() - 1; j++)
            {
                rec[i].push_back(max(rec[i - 1][j] - 1, 0.0) / 2 + 
                                 max(rec[i - 1][j + 1] - 1, 0.0) / 2); 
                rec[i - 1][j] = rec[i - 1][j] > 1 ? 1 : rec[i - 1][j];
            }
            rec[i].push_back(max(0.0, rec[i - 1][rec[i - 1].size() - 1] - 1.0) / 2);
            rec[i - 1][rec[i - 1].size() - 1] = rec[i - 1][rec[i - 1].size() - 1] > 1 ?
            1 : rec[i - 1][rec[i - 1].size() - 1];
        }
        // for(int i = 0; i < 5; i++)
        // {
        //     for(int j = 0; j < rec[i].size(); j++)
        //     {
        //         cout<<rec[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return rec[r][c];
    }
};
