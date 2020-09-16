class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> rec;
        
        if(s.length()<=10)
            return res;
        
        for(int i = 0; i < s.length() - 9; i++)
        {
            cout<<"ss\n";
            rec[s.substr(i, 10)]++;
        }
        
        for(auto i = rec.begin(); i != rec.end(); i++)
        {
            if(i->second > 1)
                res.push_back(i->first);
        }
        return res;
    }
};
