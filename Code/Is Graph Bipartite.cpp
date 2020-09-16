class Solution {
public:
    bool check(vector<vector<int>>& A, vector<int>& col, int V)
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
                if(col[A[u][i]] == -1){
                    col[A[u][i]] = 1 - col[u];
                    q.push(A[u][i]);
                }
                else if(col[A[u][i]] == col[u])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
        {
            if(col[i] == -1)
                if(!check(graph, col, i))
                    return false;
        }
        return true;
    }
};
