class Solution {
public:
    bool isNumber(string s) 
{ 
        if(s[0] == '-' && s.length() > 1)
        {
            return true;
        }
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 
    int evalRPN(vector<string>& A) {
        stack<int> s;
        int n = A.size();
        for(int i = 0; i < n; i++)
        {
            if(isNumber(A[i]))
            {
                s.push(stoi(A[i]));
            }
            else
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int res = 0;
                cout<<a<<" "<<A[i]<<" "<<b<<endl;
                if(A[i] == "+")
                {
                    res = a + b;
                }
                if(A[i] == "-")
                {
                   res = a - b;
                }
                if(A[i] == "*")
                {
                    res = a * b;
                }
                if(A[i] == "/")
                {
                    res = a / b;
                }
                cout<<res<<endl;
                s.push(res);
            }
        }
        return s.top();
        
    }
};
