class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        stack<int> s;
        for(int i = 0; i < A.size(); i++)
        {
            if(s.empty())
            {
                s.push(A[i]);
                continue;
            }
            if(s.top() * A[i] > 0)
            {
                //cout<<i<<" ";
                s.push(A[i]);
            }
            else
            {
                if(A[i] < 0)
                {
                    if(abs(s.top()) == abs(A[i]))
                    {
                        s.pop();
                        continue;
                    }
                    if(s.top() > abs(A[i]))
                    {
                        continue;
                    }
                    else
                    {
                        bool flag = false;
                        while(!s.empty())
                        {
                            cout<<s.top()<<" ";
                            if(s.top() * A[i] >= 0)
                            {
                                flag = true;
                                break;
                            }
                            if((s.top()) < abs(A[i]))
                            {
                                s.pop();
                                flag = true;
                            }
                            else if((s.top()) == abs(A[i]))
                            {
                                flag = false;
                                s.pop();
                                break;
                            }
                            else
                            {
                                flag = false;
                                break;
                            }
                    }
                    if(flag)
                        s.push(A[i]);
                    }
                }
                else
                {
                    s.push(A[i]);
                }
            }
        }
        //cout<<s.size()<<" ";
        vector<int> res;
        if(s.empty())
            return res;
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
