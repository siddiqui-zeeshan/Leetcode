class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=s1.length();
        if(l>s2.length())
            return false;
        //sort(s1.begin(), s1.end());
        multimap<char, int> m1;
        multimap<char, int> m2;
        for(int i=0;i<s1.length();i++)
        {
            m1.insert(pair<char, int>(s1[i], 0));
        }
        int j=0;
        for(int i=0;i<s2.length();i++)
        {
            if(m2.size()<l)
                m2.insert(pair<char, int>(s2[i],0));
            if(m2.size()==l)
            {
                if(m1==m2)
                    return true;
                else
                {
                    auto x=m2.find(s2[j]);
                    m2.erase(x);
                    j++;
                }
            }
        }
        return false;
    }
};
