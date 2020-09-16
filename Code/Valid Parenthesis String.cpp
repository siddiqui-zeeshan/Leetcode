class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        set<int> rec;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            if(s[i] == ')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    if(rec.size() > 0)
                    {
                        auto x = rec.begin();
                        rec.erase(x);
                    }
                    else
                        return false;
                }
            }
            if(s[i] == '*')
            {
                rec.insert(i);
            }
        }
        if(st.size() == 0)
            return true;
        while(!st.empty())
        {
            int x = st.top();
            st.pop();
            auto itr = rec.upper_bound(x);
            if(itr != rec.end())
            {
                rec.erase(itr);
            }
            else
                return false;
        }
        return true;
        
    }
};
