class Solution {
private:
    
public:
    //const int MAX=100000;
    int id[100000], nodes, edges;
    pair<long long, pair<long long, long long> > p[100000];
    void initialise()
    {
        for(int i=0;i<100000; i++)
        {
            id[i]=i;
        }
        
    }
    int root(int x)
    {
        while(x!=id[x])
        {
            id[x]=id[id[x]];
            x=id[x];
        }
        return x;
        
    }
    void Union(int x, int y)
    {
        x=root(x);
        y=root(y);
        id[x]=id[y];
    }
    long long kruskal(pair<long long, pair<long long, long long> > p[])
    {
        long long int cost=0, minCost=0;
        int x, y;
        for(int i=0; i<edges; i++)
        {
            x=p[i].second.first;
            y=p[i].second.second;
            cost=p[i].first;
            //cout<<x<<" "<<y<<" "<<cost<<"\n";
            if(root(x)!=root(y))
            {
                minCost+=cost;
                Union(x, y);
                
            }
        }
        return minCost;
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        initialise();
        edges=connections.size();
        if((N-1)>connections.size())
            return -1;
        for(int i=0;i<connections.size();i++)
        {
            p[i]=make_pair(connections[i][2], make_pair(connections[i][0], connections[i][1]));
        }
        sort(p, p+connections.size());
        long long int x= kruskal(p);
        return x;
    }
};
