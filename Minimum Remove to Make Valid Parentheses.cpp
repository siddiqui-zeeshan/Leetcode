class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l=s.length();
        stack<int> st;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(' || (st.empty() && s[i]==')'))
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(s[st.top()]=='(')
                    st.pop();
                else
                    st.push(i);
            }
        }
        string w="";
        unordered_set<int> rec;
        while(!st.empty())
        {
            rec.insert(st.top());
            st.pop();
        }
        for(int i=0;i<l;i++)
        {
            if(rec.find(i)==rec.end())
            {
                w.push_back(s[i]);
            }
        }
        return w;
    }
};
