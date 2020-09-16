class Solution {
public:
    int numberOfDays(int Y, int M) {
        switch(M)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
        }
        if ((Y % 400) == 0)
            return 29;
        else if(Y %100==0)
            return 28;
        else if(Y%4==0)
            return 29;
        else 
            return 28;
        
        
    }
};
