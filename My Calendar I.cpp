class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto itr = mp.upper_bound(start);
        if(itr == mp.end()) 
        {
            mp.insert({end, start});
            return true;
        }
        else
        {
            if(end <= itr->second)
            {
                mp.insert({end, start});
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
