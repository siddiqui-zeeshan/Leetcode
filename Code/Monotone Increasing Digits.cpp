class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string num = to_string(N);
        int pos = 1;
        while(pos < num.length() && num[pos] >= num[pos - 1]) {
            pos++;
        }
        if(pos == num.length()) 
            return N;
        while(pos - 1 >= 0 && num[pos - 1] > num[pos])
        {
            num[pos - 1]--;
            pos--;
        }
        for(int i = pos + 1; i < num.length(); i++) {
            num[i] = '9';
        }
        return stoi(num);
    }
};
