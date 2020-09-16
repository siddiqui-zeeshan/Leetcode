class Solution {
public:
    vector<int> minutes(vector<string> s)
    {
        vector<int> res;
        for(int i = 0; i < s.size(); i++)
        {
            int h = stoi(s[i]);
            int j = 0;
            while(j < s[i].length() && s[i][j] != ':')
                j++;
            int m = stoi(s[i].substr(j + 1));
            //cout<<h<<" "<<m<<endl;
            int minute = h * 60 + m;
            res.push_back(minute);
            // if(h == 0)
            // {
            //     minute = 24 * 60 + m;
            //     //cout<<minute;
            //     res.push_back(minute);
            // }
        }
        return res;
    }
    int findMinDifference(vector<string>& A) {
        vector<int> m = minutes(A);
        sort(m.begin(), m.end());
        // for(auto i : m)
        //     cout<<i<<" ";
        int mindif = INT_MAX;
        
        for(int i = 1; i < m.size(); i++)
        {
            mindif = min(mindif, m[i] - m[i - 1]);
        }
        mindif = min(mindif, 24 * 60 + m[0] - m[m.size() - 1]);
        return mindif;
    }
};
