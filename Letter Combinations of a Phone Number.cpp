class Solution {
public:
    void comb(vector<string> &res, vector<string> &dict, string A, string digits,int pos) {
        if(digits.length()==0)
            res.push_back(A);
        for(int i=pos;i<digits.length();i++)
        {
            for(int j=0;j<dict[digits[i]-'0'].size();j++)
            {
                char c=dict[digits[i]-'0'][j];
                A+=c;
                char ch=digits[i];
                digits.erase(i,1);
                comb(res,dict,A,digits,i);
                digits.insert(i,1,ch);
                A.erase(A.length()-1,1);
            }
        }
    }
        
        
        
        
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string A="";
        vector<string> dict(10);
         if(digits.length()==0)
            return res;
        dict[2]="abc";
        dict[3]="def";
        dict[4]="ghi";
        dict[5]="jkl";
        dict[6]="mno";
        dict[7]="pqrs";
        dict[8]="tuv";
        dict[9]="wxyz";
        
        comb(res,dict,A,digits,0);
        return res;
    }
};
