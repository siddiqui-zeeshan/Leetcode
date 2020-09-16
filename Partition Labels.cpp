class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<vector<int>> f(26, vector<int>(2, -1));
        for(int i = 0; i < S.length(); i++)
        {
            if(f[S[i] - 'a'][0] == -1)
                f[S[i] - 'a'][0] = i;
            f[S[i] - 'a'][1] = i;
        }
        int l = 0;
        int r = f[S[0] - 'a'][1];
        // for(auto i : f)
        // {
        //     cout<< i[0] << " "<< i[1]<<endl;
        // }
        
        for(int i = 0; i < S.size(); i++)
        {
            if(i < r)
            {
                if(f[S[i] - 'a'][1] > r)
                {
                    r = f[S[i] - 'a'][1];
                }
                if(i == r)
                {
                    
                }
            }
            else if(i == r)
            {
                res.push_back(r - l + 1);
                l = i + 1;
                if(i < S.length() - 1)
                {
                    r = f[S[i + 1] - 'a'][1];
                }
            }
        }
        if(r > l)
        {
            res.push_back(r - l + 1);
        }
        return res;
    }
};
