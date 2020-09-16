class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> rec;
        int rowsum = 0;
        for(int i = 0; i < wall.size(); i++)
        {
            int sum = wall[i][0];
            rec[wall[i][0]]++;
            for(int j = 1; j < wall[i].size(); j++)
            {
                //cout<<i<<" "<<j<<endl;
                sum += wall[i][j];
                rec[sum]++;
            }
            rowsum = sum;
        }
        int rows = 0;
        
        for(auto i : rec)
        {
            if(i.first != rowsum){
            rows = max(rows, i.second);
            }
        }
        return wall.size() - rows;
    }
};
