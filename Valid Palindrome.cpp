class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r)
        {
            char x = s[l];
            char y = s[r];
            x = tolower(x);
            y = tolower(y);
            //cout << x << " " << y;
            if(isalnum(x) && isalnum(y) && x == y)
            {
                l++;
                r--;
            }
            else if(isalnum(x) && isalnum(y) && x != y)
            {
                return false;
            }
            else if(!isalnum(x) && isalnum(y))
            {
                l++;
            }
            else if(isalnum(x) && !isalnum(y))
            {
                r--;
            }
            else if(!isalnum(x) && !isalnum(y))
            {
                r--;
                l++;
            }
    
        }
        return true;
        
    }
};
