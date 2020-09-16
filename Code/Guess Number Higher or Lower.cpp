// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n)
{
    unsigned int low = 1;
    int mid = n;

    int guess_result = guess(mid);

    while(guess_result != 0)
    {
        if(guess_result == -1)
        {
            n = mid;
        }
        else if(guess_result == 1)
        {
            low = mid;
        }
        
        mid = (low+n)/2;
        guess_result = guess(mid);
    }
    return mid;
}

};
