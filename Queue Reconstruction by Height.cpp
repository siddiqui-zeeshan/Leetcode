class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[1] < b[1] || (a[1] == b[1] && a[0] <= b[0]));
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        if(people.size() == 0)
            return res;
        sort(people.begin(), people.end(), comp);
        res.push_back(people[0]);
        
        for(int i = 0; i < people.size(); i++)
        {
            cout<<people[i][0]<<" "<<people[i][1]<<endl;
        }

        for(int i = 1; i < people.size(); i++)
        {
            int count = 0;
            int pos = 0;
            for(int j = 0; j < res.size(); j++)
            {
                
                if(people[i][0] > res[j][0])
                {
                    pos++;
                }
                else if(res[j][0] >= people[i][0] && count < people[i][1])
                {
                    count++;
                    pos++;
                }
                
                // if(count == people[i][1]) 
                // {
                //     if(people[i][0] <= res[j][0])
                //     {
                //         res.insert(res.begin() + j, people[i]);
                //     } 
                //     else 
                //     {
                //         res.insert(res.begin() + j + 1, people[i]);
                //     }
                //     break;
                // }
            }
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }
};
