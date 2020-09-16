class Solution {
public:
    struct Log {
        int id;
        string status;
        int timestamp;
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> times(n, 0);
        stack<Log> st;
        //int t = 0;
        for(auto log : logs)
        {
            stringstream ss(log);
            string temp, temp2, temp3;
            getline(ss, temp, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');

            Log item = {stoi(temp), temp2, stoi(temp3)};
            if(item.status == "start")
                st.push(item);
            else
            {
                Log temp = st.top();
                st.pop();
                int t = item.timestamp - temp.timestamp + 1;
                times[item.id] += t;
                if(!st.empty())
                times[st.top().id] -= t;
            }
        }
        return times;
    }
};
