class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        while(true)
        {
            for(int i = 0; i < n; i++)
            {
                if(senate[i] != 'x')
                {
                    int j = (i + 1) % n;
                    while(true)
                    {
                        if(j == i)
                            break;
                        if(senate[j] != senate[i] && senate[j] != 'x')
                            break;
                        //cout<<senate[j]<<" ";
                        j = (j + 1) % n;
                    }
                    if(i == j)
                        return senate[i] == 'R' ? "Radiant" : "Dire";
                    else
                        senate[j] = 'x';
                }
            }
        }
        return "";
    }
};
