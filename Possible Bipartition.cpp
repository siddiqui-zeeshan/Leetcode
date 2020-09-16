class Solution {
public:
    bool check(vector<vector<int>>& A, int V, vector<int>& col)
    {
        col[V] = 1;
        queue<int> q;
        q.push(V);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < A[u].size(); i++)
            {
                if(col[A[u][i]] == -1)
                {
                    col[A[u][i]] = 1 - col[u];
                    q.push(A[u][i]);
                }
                else if(col[A[u][i]] == col[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> A(N + 1);
        for(int i = 0; i < dislikes.size(); i++)
        {
            int v1 = dislikes[i][0];
            int v2 = dislikes[i][1];
            A[v1].push_back(v2);
            A[v2].push_back(v1);
        }
        vector<int> col(N + 1, -1);
        
        for(int i = 1; i <= N; i++)
        {
            if(col[i] == -1 && check(A, i, col) == false)
                return false;
        }
        return true;
    }
};
