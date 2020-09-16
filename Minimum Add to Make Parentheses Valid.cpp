class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]==')' && !s.empty() && s.top()=='(')
            {
                s.pop();
            }
            else
            {
                s.push(S[i]);
            }
        }
        return s.size();
    }
};
