class Solution {
public:
    string reorganizeString(string S) {
        vector<int> f(26, 0);
        for(auto i : S)
            f[i - 'a']++;
        multimap<int, char, greater<int>> rec;
        for(int i = 0; i < 26; i++)
        {
            if(f[i] != 0)
            rec.insert({f[i], i + 'a'});
        }
        string res = "";
        for(int i = 0; i < S.size(); i++)
        {
            if(res.size() == 0 || res[res.length() - 1] != rec.begin()->second)
            {
                int a = rec.begin()->first;
                char b = rec.begin()->second;
                rec.erase(rec.begin());
                res += b;
                a--;
                if(a > 0)
                    rec.insert({a, b});
            }
            else if(res[res.length() - 1] == rec.begin()->second)
            {
                if(rec.size() == 1)
                    break;
                auto t = rec.begin();
                t++;
                int a = t->first;
                char b = t->second;
                rec.erase(t);
                res += b;
                a--;
                if(a > 0)
                    rec.insert({a, b});
            }
        }
        return res.size() == S.size() ? res : "";
    }
};
