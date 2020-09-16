class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i])
            {
                secret[i] = '*';
                guess[i] = '*';
                bull++;
            }
        }
        vector<int> f1(10, 0);
        vector<int> f2(10, 0);
        for(int i = 0; i < secret.size(); i++)
        {
            if(isalnum(secret[i]))
                f1[secret[i] - '0']++;
            if(isalnum(guess[i]))
                f2[guess[i] - '0']++;
        }
        
        for(int i = 0; i < 10; i++)
        {
            if(f1[i] != 0)
                cow += min(f1[i], f2[i]);
        }
        string res = to_string(bull)+"A"+to_string(cow)+"B";
        return res;
    }
};
