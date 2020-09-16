class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int k = mat.size() - 1; k >= 0; k--)
        {
            int i = k;
            int j = 0;
            vector<int> A;
            while(i < mat.size() && j < mat[0].size())
            {
                A.push_back(mat[i][j]);
                i++;
                j++;
            }
            // for(auto i : A)
            //     cout<<i<<" ";
            // cout<<endl;
            sort(A.begin(), A.end());
            i = k;
            j = 0;
            int poi = 0;
            while(i < mat.size() && j < mat[0].size())
            {
                mat[i][j] = A[poi];
                i++;
                j++;
                poi++;
            }
        }
        for(int k = 0; k < mat[0].size(); k++)
        {
            int j = k;
            int i = 0;
            vector<int> A;
            while(i < mat.size() && j < mat[0].size())
            {
                A.push_back(mat[i][j]);
                i++;
                j++;
            }
            // for(auto i : A)
            //     cout<<i<<" ";
            // cout<<endl;
            sort(A.begin(), A.end());
            i = 0;
            j = k;
            int poi = 0;
            while(i < mat.size() && j < mat[0].size())
            {
                mat[i][j] = A[poi];
                i++;
                j++;
                poi++;
            }
        }
        return mat;
    }
};
