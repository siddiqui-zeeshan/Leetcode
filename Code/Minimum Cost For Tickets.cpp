class Solution {
public:
    int nextDay(vector<int>& days, int dayIndex, int duration)
    {
        int endDay = days[dayIndex] + duration - 1;
        int newDayIndex = dayIndex;
        
        while (newDayIndex < days.size() && days[newDayIndex] <= endDay) {
            newDayIndex++;
        }
        
        return newDayIndex;
    }
    int cost(vector<int>& days, vector<int>& costs, int pos, vector<int>& memo)
    {
        if(pos >= days.size())
            return 0;
        if(memo[pos] != -1)
            return memo[pos];
        int a = costs[0] + cost(days, costs, nextDay(days, pos, 1), memo);
        int b = costs[1] + cost(days, costs, nextDay(days, pos, 7), memo);
        int c = costs[2] + cost(days, costs, nextDay(days, pos, 30), memo);
        memo[pos] = min(a, min(b, c));
        return memo[pos];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size() + 10, -1);
        return cost(days, costs, 0, memo);
    }
};
