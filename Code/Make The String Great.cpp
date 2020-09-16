class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto i : s)
        {
            if(st.empty())  
            {
                st.push(i);
            }
            else if((st.top() != (i - 'A' + 'a') && (st.top() - 'A' + 'a') != i))
            {
                st.push(i);
            }
            else
            {
                st.pop();
            }
        }
        string ans = "";
        while(st.size())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
